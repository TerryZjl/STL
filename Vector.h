#include<iostream>
using namespace std;

template<class T>
class Vector
{
	typedef T Node;
public:
	typedef T* Iterator;

	Vector()
		:_start(NULL)
		, _finish(NULL)
		, _end(NULL)
	{}

	void PushBack(const T& x)
	{
		Expend();
		Insert(_finish, x);
	}

	Iterator Insert(Iterator pos, const T& x)
	{
		int len = Size();
		int n = pos - _start;

		Expend();
		if (pos == _finish)
		{
			*_finish = x;
			_finish++;
		}
		else
		{
			while (len >= n)
			{
				_start[len] = _start[len - 1];
				len--;
			}
			_start[n] = x;
			_finish++;
		}
		return pos;
	}
	Iterator& Begin()
	{
		return _start;
	}
	Iterator& End()
	{
		return _finish;
	}
	size_t Size()
	{
		return _finish - _start;
	}

private:
	void Expend()
	{
		if (_end > _finish)
		{
			return;
		}
		size_t capacity = _end - _start;
		size_t len = 2 * (capacity + 1);
		Node* NewNode = GetNode(len);
		
		//浅拷贝
		//memcpy(NewNode, _start, (capacity)* 4);

		//深拷贝
		Node* cur = NewNode;
		for (int i = 0;i<capacity;i++)
		{
			*cur = *(_start + i);
			cur++;
		}
		delete[] _start;
		_start = NewNode;
		_finish = NewNode + capacity;
		_end = NewNode + len;
	}

	Node* GetNode(size_t len)
	{
		return new Node[len];
	}
private:
	Node* _start;
	Node* _finish;
	Node* _end;
};

int main()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	Vector<int>::Iterator it = v.Begin();
	it++;
	v.Insert(it, 5);
	it = v.Begin();
	while (it != v.End())
	{
		
		cout << *it << " ";
		it++;
	}
	return 0;
}{\rtf1}