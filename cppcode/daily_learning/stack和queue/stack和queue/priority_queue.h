#pragma once
#include<iostream>
#include<vector>
namespace caige
{
	template<class T>
	class Lesser
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};
	template<class T>
	class Greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};
	template<class T,class Container =std::vector<T>,class Compare=Lesser<T> >
	class priority_queue
	{
	public:
		//默认大的权重大，默认是大堆，
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
			AdjustUp(_con.size()-1);
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			/*AdjustDown(0);
			_con.pop_back();*///应该先删除，再调整
			_con.pop_back();
			AdjustDown(0);
			//_size--(
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
		//自己的实现过程：
		//默认是大堆
		void AdjustUp(int child)
		{
			int paret = (child-1) / 2;
			//while (child >= 0 && _con[child] > _con[parent])
			//while (child >= 0 && _con[parent] < _con[child] )
			while (child >= 0 && com(_con[parent] , _con[child]))//因为默认是lesser，所以， com(_con[parent] , _con[child])返回真就是_con[parent] < _con[child]
			{
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
		}//前提是左右子树都是大根堆堆
		void AdjustDown(int parent)//默认是从堆顶开始调整，调整到堆底，
		{
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				//if (child + 1 < _con.size() && _con[child + 1] > _con[child])//同理，因为默认是lesser仿函数这里要放小于号魔所以，要换一下位置，
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
					if (child + 1 < _con.size() && com(_con[child] < _con[child + 1]))
				{
					child++;
				}
					if (com(_con[parent] ，_con[child]))//同理
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else break;
			}
		}
		//第一次写的错误代码：
		////前提是左右子树都是大根堆堆
		//void AdjustDown(int parent)//默认是从堆顶开始调整，调整到堆底，
		//{
		//	int less = parent * 2 + 1;
		//	int bigger = parent * 2 + 2;
		//	if (_con[less] > _con[bigger])
		//		swap(less, bigger);
		//	while (_con[bigger] > _con[parent] && parent < _con.size())
		//	{
		//		swap(_con[bigger], _con[parent]);
		//		less = parent * 2 + 1;
		//		bigger = parent * 2 + 2;
		//		if (_con[less] > _con[bigger])
		//			swap(less, bigger);
		//	}

		//}
	private:
		Container _con;
		//size_t _size=0;
	};
	
}

