#pragma once
#include<iostream>
#include<vector>
namespace caige
{
	
	template<class T,class Container =std::vector<T>,class Compare=Lesser<T> >
	class priority_queue
	{//默认大的权重大，默认是大堆，
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] < _con[child])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustDown(int parent)
		{
			// 先假设左孩子小
			size_t child = parent * 2 + 1;

			Compare com;
			while (child < _con.size())  // child >= n说明孩子不存在，调整到叶子了
			{
				// 找出小的那个孩子
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				//if (_con[parent] < _con[child])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp();
		}
		void pop()
		{
			swap(_con[0], _con[_con._size() - 1]);
			AdjustDown();
			_con.pop();
			//_size--;
		}
		T& top()
		{
			return _con[0];
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
		//size_t _size=0;
	};
}
