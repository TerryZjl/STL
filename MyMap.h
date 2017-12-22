#ifndef _MYMAP_H_
#define _MYMAP_H_

#include<iostream>
#include"MyTree.h"
#include<string>
using namespace std;

template<class K, class V>
struct KeyOfValue
{
	K operator()(const V& value)
	{
		return value.first;
	}
};

template<class K, class V>
class MyMap
{
	typedef K KeyType;
	typedef pair<const K, V> ValueType;
	typedef  RBTree<KeyType, ValueType,KeyOfValue<KeyType,ValueType>> MapNode;
public:
	typedef typename MapNode::Iterator Iterator;
	pair<Iterator,bool> Insert(const ValueType& value)
	{
		return _node.Insert(value);
	}
	Iterator Find(const KeyType& key)
	{
		return _node.Find(key);
	}
	V& operator[](const KeyType& key)
	{
		pair<Iterator,bool> ret = _node.Insert(make_pair(key, V()));
		return (ret.first)->second;
	}


	Iterator Begin()
	{
		return _node.Begin();
	}
	Iterator End()
	{
		return Iterator();
	}
	

private:
	MapNode _node;
};


void TestMyMap()
{
	
	MyMap<string,string> map;

	map.Insert(make_pair("张三", "zhangsan"));
	map.Insert(make_pair("李四", "lisi"));
	//map.Insert(make_pair("王麻子", "wangmazi"));
	map["张三"] = "wangmazi";
	map.Insert(make_pair("我们不一样", "no soy como"));
	
	MyMap<string,string>::Iterator it1 = map.Begin();
	while (it1 != map.End())
	{
		cout << (*(it1)).first<< "：" << it1->second << endl;
		++it1;
	}
	it1 = map.Find("王麻子");
	if (it1!=map.End())
		cout << it1->second << endl;
	
}

#endif