#pragma once
#include<iostream>
using namespace std;
namespace caige
{
	template <class T>
	class ListNode
	{
	public:
		template<class>
		friend class List;
		ListNode(const T& t)//为什么加const，因为要支持右值ListNode( T&& t)
			:_t(t)
			,_next(nullptr)
		{
		}
	private:
		T _t;
		ListNode* _next;
	};
	template <class T>
	class List
	{
	public :
		typedef ListNode<T> Node;
		List(Node* head)
			:_head(head)
		{ }
		~List()
		{
			Node* cur = _head;
			Node* next = cur->_next;
			while (cur)
			{
				delete cur;
				cur = next;
				if(cur)
				next = cur->_next;
			}
		}
		void clear()
		{
			Node* cur = _head->_next;
			Node* next = cur->_next;
			while (cur)
			{
				delete cur;
				cur = next;
				if (cur)
					next = cur->_next;
			}
			_head->_next = nullptr;
		}
		size_t size()
		{
			Node* cur = _head;
			size_t size = 0;
			while (cur)
			{
				size++;
				cur = cur->_next;
			}
			return size;
		}
		bool emptry()
		{
			return _head->_next == nullptr;
		}
		T& geti(size_t i)
		{
			Node* cur = _head;
			while (i--)
			{
				if(cur)
				cur = cur->_next;
				
			}
			return cur->_t;
		}
	private:
		Node* _head = nullptr;
	};

}