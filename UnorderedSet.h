#ifndef _UNORDERSET_H_
#define _UNORDERSET_H_

#include<iostream>
#include"Hash.h"
using namespace std;

template<class K>
struct CompereSet
{
	const K& operator()(const K& value) const 
	{
		return value;
	}
};
template<class K>
class UnOrderSet
{
	typedef LINK::HashTable<K, K, CompereSet<K>> SetNode;
public:
	typedef typename SetNode::Iterator Iterator;


	pair<Iterator,bool> Insert(const K& key)
	{
		return set.Insert(key);
	}
	
	Iterator Find(const K& key)
	{
		return set.Find(key);
	}

	bool Remove(const K& key)
	{
		return set.Remove(key);
	}
	Iterator End()
	{
		return set.End();
	}
	Iterator Begin()
	{
		return set.Begin();
	}
private:
	SetNode set;
};

void TestUnOrderSet()
{
	UnOrderSet<int> s;
	for (int i = 0; i < 1000; i++)
		s.Insert(i);
	UnOrderSet<int>::Iterator it = s.Begin();
	int i = 0;
	while (it != s.End())
	{
		cout << *it << " ";
		i++;
		if (i == 10)
		{
			cout << endl;
			i = 0;
		}
		++it;
	}
	cout << endl;

	it = s.Find(553);
	if (it != s.End())
		cout << "find"<<*it << endl;

	s.Remove(553);
	it = s.Find(553);

	if (it == s.End())
		cout << "没找到"<< endl;

}

#endif //_UNORDERSET_H_