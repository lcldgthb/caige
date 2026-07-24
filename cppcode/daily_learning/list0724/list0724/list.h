#/*pragma once
#include<iostream>
using namespace std;
namespace caige {

	template <class T>
	class _listNode
	{
		typedef _listNode<T> node;

		T _data;
		_listNode<T>* _next;
		_listNode<T>* _prev;
	};
	template <class T>
	class list
	{
		list()
		{

		}
	private :
		node* _head;
	};
}*/

#pragma once

namespace caige
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& data = T())
			:_data(data)
			, _next(nullptr)
			, _prev(nullptr)
		{
		
		}
	};

	template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T> Self;

		Node* _node;

		list_iterator(Node* node)
			:_node = node
		{

		}

		T& operator*()
		{
			return _node->_data;
		}

		Self& operator++()//前置++
		{
			_node = _node->_next;
			//return _node;注意返回类型
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			//return _node;注意返回类型
			return *this;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;

	public:
		typedef list_iterator<T> iterator;

		list()
			:_head (nullptr)
			, _size (0)
		{

		}
		~list()
		{
			clear();
			delete _head;
		}
		list(const list& l)
		{
			Node* head = new Node();
			_head = head;
			//哨兵节点没有很好的初始化
			_head->_next = _head;
			_head->_prev = _head;
			//size也没有初始化
			_size = 0;
			for (auto it =l.begin(); it != l.end(); ++it)
			{
				push_back(*it);
			}
		}
		list& operator= (const list & l)
		{
			list tmp(l);
			swap(tmp);
			return *this;
		}
			void swap(list& l)
		{
			std::swap(_head, l._head);
			//忘记交换size
			std::swap(_size, l._size);
		}
		iterator begin()
		{
			//return iterator(_head);我们实现的是带头双向循环链表，所以，有头结点
			return iterator(_head->_next);
		}

		iterator end()
		{
			//return iterator(_head);我们实现的是带头双向循环链表，所以，有头结点
			return iterator(_head);
		}

		void push_back(const T& x)
		{
			//assert(empty());回想一下判断空指针，assert(p);
			//assert(!empty());实际上这里根本不需要 assert。因为 push_back() 本来就应该支持：
				//空链表插入,非空链表插入
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void insert(iterator pos, const T& x)
		{
			//Node newnode(x);不能定义在栈上
			Node* newnode = new Node(x);
			newnode->_next = pos._node;
			newnode->_prev = pos._node->_prev;
			//pos._node->_prev->_next = newnode;
			pos._node->_prev->_next = newnode;
			pos._node->_prev = newnode;
			//别忘了维护size
			_size++;
		}

		void pop_back()
		{
			assert(!empty());
			erase(--end());//删除后迭代器里面的node还是指向_head,所以，不用管
			_size--;
		}

		void pop_front()
		{
			assert(!empty());
			erase(begin());//同理，不用管
			//_size--;重复维护size！！！！！！

		}

		void erase(iterator pos)
		{
			//不能删除end
			assert(pos != end());
			pos._node->_prev->_next = pos._node->_next;
			pos._node->_next->_prev = pos._node->_prev;
			//delete (*pos);不对！！！
			// delete  *(pos._node);也不对！！
			// delete 的参数必须是一个指针，但是释放的是这个指针所指向的对象。
			delete pos._node;
			//别忘了维护size
			size--;
		}
		void clear()
		{
			//这个不能简单的移动指针，而要全部删除
			//for (auto it = begin(); it != end(); ++it)
			//{
			//	//erase(it);经典问题，迭代器失效
			//	/*iterator tmp = it;
			//	erase(tmp);*///这样也是不对的，还是失效
			//}
			// erase 后 tmp 会失效，因此必须提前保存下一个位置
			auto it = begin();
			while (it != end())
			{
				auto tmp = it;
				++it;//必须先让他走到下一个位置
				erase(tmp);
			}
			//最简单的写法：
			/*while (!empty())
			{
				pop_back();
			}*/
		}
		size_t size() const
		{
			return _size;
		}

		bool empty() const
		{
			return _size == 0;
		}

	private:
		Node* _head;
		size_t _size;
	};

	template<class T>
	list_node<T>::list_node(const T& data)
	{

	}

	template<class T>
	list_iterator<T>::list_iterator(Node* node)
	{

	}

	template<class T>
	T& list_iterator<T>::operator*()
	{

	}

	template<class T>
	typename list_iterator<T>::Self& list_iterator<T>::operator++()
	{

	}

	template<class T>
	typename list_iterator<T>::Self& list_iterator<T>::operator--()
	{

	}

	template<class T>
	bool list_iterator<T>::operator!=(const Self& s) const
	{

	}

	template<class T>
	bool list_iterator<T>::operator==(const Self& s) const
	{

	}

	template<class T>
	list<T>::list()
	{

	}

	template<class T>
	typename list<T>::iterator list<T>::begin()
	{

	}

	template<class T>
	typename list<T>::iterator list<T>::end()
	{

	}

	template<class T>
	void list<T>::push_back(const T& x)
	{

	}

	template<class T>
	void list<T>::push_front(const T& x)
	{

	}

	template<class T>
	void list<T>::insert(iterator pos, const T& x)
	{

	}

	template<class T>
	void list<T>::pop_back()
	{

	}

	template<class T>
	void list<T>::pop_front()
	{

	}

	template<class T>
	void list<T>::erase(iterator pos)
	{

	}

	template<class T>
	size_t list<T>::size() const
	{

	}

	template<class T>
	bool list<T>::empty() const
	{

	}

	void test_list1();
}