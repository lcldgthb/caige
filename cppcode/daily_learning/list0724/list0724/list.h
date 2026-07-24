#pragma once
#include<iostream>
#include<assert.h>
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
	//template<class T, class T&, class T*>
	  template<class T,class Ref ,class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T,Ref,Ptr> Self;

		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{

		}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()//要达到的效果，迭代器it it->_al,所以，返回的是T*
		{
			return &_node->_data;
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
		Self operator++(int)//后置++
		{
			Self tmp(_node);
			_node = _node->_next;
			return tmp;
		}
		Self operator--(int)//后置--
		{
			Self tmp(_node);
			_node = _node->_prev;
			return tmp;
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
	//typedef list_iterator<int, int&, int*> iterator;
	//typedef list_iterator<const int,const int&, const int*> iterator;
	

	template<class T>
	class list
	{
	
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
	
		
	
		//typedef list_iterator<T> iterator;

		/*list()
			:_head (nullptr)
			, _size (0)
		{

		}*/
		list()
		{
			emptry_init();
		}
		~list()
		{
			clear();
			delete _head;
		}
		void emptry_init()
		{
			Node* head = new Node();
			_head = head;
			//哨兵节点没有很好的初始化
			_head->_next = _head;
			_head->_prev = _head;
			//size也没有初始化
			_size = 0;
		}
		list(const list& l)
		{
			emptry_init();
			for (auto it = l.begin(); it != l.end(); ++it)
			{
				push_back(*it);
			}
		}
		//list()
		//{
		//	Node* head = new Node();
		//	_head = head;
		//	//哨兵节点没有很好的初始化
		//	_head->_next = _head;
		//	_head->_prev = _head;
		//	//size也没有初始化
		//	_size = 0;
		//}
		/*list(const list& l)
		{
			list();
			for (auto it = l.begin(); it != l.end(); ++it)
			{
				push_back(*it);
			}
		}*/
		//list& operator= (const list & l)
		//{
		//	list tmp(l);
		//	swap(tmp);
		//	return *this;
		//}
			void swap(list& l)
		{
			std::swap(_head, l._head);
			//忘记交换size
			std::swap(_size, l._size);
		}
		
		list& operator=(list l)
		{
			swap(l);
			return *this;
		}
		//iterator begin()
		//{
		//	//return iterator(_head);我们实现的是带头双向循环链表，所以，有头结点
		//	return iterator(_head->_next);
		//}

		//iterator end()
		//{
		//	//return iterator(_head);我们实现的是带头双向循环链表，所以，有头结点
		//	return iterator(_head);
		//}

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

		//void insert(iterator pos, const T& x)
		//{
		//	//Node newnode(x);不能定义在栈上
		//	Node* newnode = new Node(x);
		//	newnode->_next = pos._node;
		//	newnode->_prev = pos._node->_prev;
		//	//pos._node->_prev->_next = newnode;
		//	pos._node->_prev->_next = newnode;
		//	pos._node->_prev = newnode;
		//	//别忘了维护size
		//	_size++;
		//}

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

		//void erase(iterator pos)
		//{
		//	//不能删除end
		//	assert(pos != end());
		//	pos._node->_prev->_next = pos._node->_next;
		//	pos._node->_next->_prev = pos._node->_prev;
		//	//delete (*pos);不对！！！
		//	// delete  *(pos._node);也不对！！
		//	// delete 的参数必须是一个指针，但是释放的是这个指针所指向的对象。
		//	delete pos._node;
		//	//别忘了维护size
		//	size--;
		//}
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
		
		// iterator接口
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}
		const_iterator end() const
		{
			return _head;
		}
		
		// 初始化
		//void empty_init();

		// 构造
		//list();
		list(std::initializer_list<T> il);
		//list(const list<T>& lt);

		

		//// 修改
		iterator insert(iterator pos, const T& x);
		iterator erase(iterator pos);

	private:
		Node* _head;
		size_t _size;
	};



	template<class T>
	list<T>::list(std::initializer_list<T> il)//只读数组：
	{
		emptry_init();
		/*for (int i = 0; i < il.size(); i++)
			push_back(il[i]);*/
		for (const auto& it : il)
			push_back(it);
	}

	//insert返回的是新插入元素的位置
	template<class T>
	typename list<T>::iterator list<T>::insert(iterator pos, const T& x)//	typename list<T>::iterator list类里面的iterator类型，不是变量 list<T>::insert(iterator pos, const T& x)
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
		return newnode;
	}

	template<class T>
	typename list<T>::iterator list<T>::erase(iterator pos)
	{
		iterator ret(pos._node->_next);
		//不能删除end
		assert(pos != end());
		pos._node->_prev->_next = pos._node->_next;
		pos._node->_next->_prev = pos._node->_prev;
		//delete (*pos);不对！！！
		// delete  *(pos._node);也不对！！
		// delete 的参数必须是一个指针，但是释放的是这个指针所指向的对象。
		delete pos._node;
		//别忘了维护size
		_size--;
		return ret;
	}

	
}