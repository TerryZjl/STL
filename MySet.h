#ifndef _MYSET_H_
#define _MYSET_H_

#include<iostream>
#include"MyTree.h"
#include<map>
using namespace std;

template<class K>   //set封装红黑结点比较的仿函数
struct KeyOfKey
{
	K operator()(const K& key)
	{
		return key;
	}
};

template<class K>
class MySet
{
	typedef K KeyType;
	typedef K ValueType;
	typedef RBTree<KeyType, ValueType,KeyOfKey<KeyType>> SetNode;

public:
	typedef typename SetNode::Iterator  Iterator;  //因为SetNode是模板类型，且还没有实例化，因此要用他得使用typename
	//typedef RBTreeIterator<ValueType, ValueType*, ValueType&> Iterator;
	
	pair<Iterator,bool> Insert(const ValueType& key)
	{
		return _node.Insert(key);
	}
	Iterator Find(const KeyType& key)
	{
		return _node.Find(key);
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
	SetNode _node;
};

void TestMySet()
{
	MySet<int> set;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < 10; i++)
	{
		set.Insert(arr[i]);
	}
	MySet<int>::Iterator it1 = set.Begin();
	while (it1 != set.End())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	it1 = set.Begin();
	it1 = set.Find(5);
	cout << *it1 << endl;  
}

#include<set>
#include<vector>




void TestUseSet()
{
	//三种定义set对象的方式
	
	//无参
	set<int, less<int> > set1;
	for (int i = 1;i<6;i++)
		set1.insert(i);

	pair<set<int>::iterator, bool> ret1 = set1.insert(10);

	cout << *(ret1.first) << endl;

	map<int,int> map1;
	pair<map<int,int>::iterator, bool> ret2 = map1.insert(make_pair(1,2));
	cout << ret2.first->first << ":" << (*(ret2.first)).second << endl;   //运行结果：1 ：2


	set<int>::iterator it1 = set1.begin();
	while (it1!=set1.end())
	{
		cout << *it1 << endl;		
		++it1;  

	}
	//set1的元素：5 4 3 2 1 

	//给一个参数区间进行初始化
	int arr[] = { 1, 2, 3, 4, 5 };
	set<int> set2(arr, arr + 4);
	set<int> set4(set1.begin(), set1.end());

	//要把自定义类型存入set，这里就需要自己写第二个比较参数。
	struct AA
	{
		int _a;
		int _b;
		AA(int a, int b)
			:_a(a)
			, _b(b)
		{}
	};
	struct ComLess //升序
	{
		bool operator()(const AA& left, const AA& right) const
		{
			return left._a < right._a;
		}
	};

	set<AA,ComLess> set3;
	set3.insert(AA(1,2));
	set3.insert(AA(3,4));
	set3.insert(AA(5,6));


	////直接插入
	//set<int>::iterator it = set1.begin();
	//it = set1.find(4);
	//set1.insert(it,5);
	//pair<set<int>::iterator,bool> Pair = set1.insert(5);
	//if (Pair.second == false)
	//{
	//	cout << "插入失败，说明5已经被插入过了" << endl;
	//}
	//else
	//{
	//	cout << "插入成功，说明5在这次插入之前还没有，现在插入了" << endl;
	//}
	////void insert(InputIterator first, InputIterator last);
	//set<int> set5(set1.begin(), set1.end());
	//删除
	
	//删除一个区间
	set<int>::iterator left = set1.lower_bound(2);  //从左往右找到第一个大于等于2的位置
	set<int>::iterator right = set1.upper_bound(3); //从左往右找到第一个大于3的位置
	set1.erase(left, right); //删除左开右闭区间
	//删除一个迭代器位置
	set<int>::iterator It = set1.begin();
	It = set1.begin();
	set1.erase(It); 
	//按值查找删除，删除成功返回1，删除失败返回0
	size_t i = set1.erase(5);
	cout << i << endl;  //1
	size_t j = set1.erase(1221);
	cout << j << endl;  //没有'1221'，则返回0
}
#endif