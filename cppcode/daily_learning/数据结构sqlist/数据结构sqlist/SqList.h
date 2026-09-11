#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;
namespace caige
{
	template<class T>
	class SqList
	{
	public :

		SqList() = default;//强制生成默认构造
		SqList(size_t n)//构造函数
		{ 
			reserve(n);
			_size = n;
		
		}
		~SqList()//析构函数
		{
			delete[] _data;
			_size = 0;
			_capacity = 0;
			_data = nullptr;
		}
		bool emptry()//判空函数
		{
			return _size == 0;
		}
		bool full()//判满函数
		{
			return _size == _capacity;
		}
		size_t size()//顺序表的大小
		{
			return _size;
		}
		T& get(size_t i)//获取第i个数
		{
			assert(i < _size);
			/*return *(_data + i );*/
			return _data[i];
		}
		size_t pos(const T& t)//获取对应元素的下标
		{
			int i = 0;
			for (; i < _size; i++)
			{
				if (_data[i] == t)
					return i;
			}
			return _size;
		}
		size_t posprev(const T& t)//获取对应元素的前一个元素的下标
		{
			int posi = pos(t)-1;
			assert(posi >=0 && posi < _size);
			return posi;
		}
		size_t posnext(const T& t)//获取对应元素的后一个元素的下标
		{
			int posi = pos(t) +1;
			assert(posi != _size);      // 没找到
			assert(posi + 1 < _size);   // 没有后继
			return posi;
		}
		void reserve(size_t n)//预留空间
		{
			if (n <= _capacity)
				return;
			_capacity = _capacity == 0 ? 4 : 2 * _capacity;
			while (_capacity <= n)
			{
				_capacity *= 2;
			}
			T* tmp= new T[_capacity];
			for (int i = 0; i < _size; i++)
			{
				tmp[i] = _data[i];
			}
			delete[] _data;//防止内存泄漏
			_data = tmp;
		}
		//void reserve(size_t n)
		//{
		//	if (n <= _capacity)
		//		return;

		//	size_t new_cap = _capacity == 0 ? 4 : 2 * _capacity;
		//	while (new_cap < n)
		//		new_cap *= 2;

		//	// 只分配裸内存，不构造任何对象
		//	T* tmp = static_cast<T*>(::operator new(  * new_cap));

		//	// placement new 拷贝构造
		//	for (size_t i = 0; i < _size; ++i)
		//	{
		//		new(tmp + i) T(_data[i]);
		//	}

		//	// 销毁旧对象
		//	for (size_t i = 0; i < _size; ++i)
		//	{
		//		_data[i].~T();
		//	}
		//	// 释放旧裸内存
		//	::operator delete(_data);

		//	_data = tmp;
		//	_capacity = new_cap;
		//}

	/*	void insert(size_t i,const T& t)
		{
				if (i < _size || full())
				{
					size_t newcapacity = _size + 1 > i ? _size + 1 : i;
					reserve(newcapacity);
				}
				
			memmove(_data + (i + 1)* , _data + i* , (_size - i) *  );
			T* dest = _data + i;
			*dest = t;
			_size++;
		}*/
		void insert(size_t i, const T& t)
		{
			assert(i <= _size);
			if (_size >= _capacity)
			{
				reserve(_size + 1);
			}
			// 后往前移动赋值
			for (size_t j = _size; j > i; j--)
			{
				_data[j] = std::move(_data[j - 1]);
			}
			_data[i] = t;
			_size++;
		}

		void deletei(size_t i)
		{
			assert(i < _size);
			for (int cur = i; cur < _size-1; cur++)
			{
				_data[cur] = _data[cur + 1];
			}
			_size--;
		}
		void print()
		{
			assert(_size != 0);
			for (int i = 0; i < _size; i++)
			{
				cout << _data[i] << "  ";
			}
			cout << endl;
		}
		void sort()
		{
			assert(!emptry());
			for (int i = 0; i < _size; i++)
			{
				for (int j = 0; j < _size-1-i; j++)
				{
					if (_data[j] > _data[j + 1])
						swap(_data[j], _data[j + 1]);
				}
			}
		}
	private:
		T* _data=nullptr;
		size_t _size=0;
		size_t _capacity = 0;
	};
}