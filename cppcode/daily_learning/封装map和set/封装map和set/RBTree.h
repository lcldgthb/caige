#pragma once
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
enum Colour
{
	RED,
	BLACK
};


template<class T>
struct RBTreeNode
{
	T _data;

	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	Colour _col;

	RBTreeNode(const T& data)
		:_data(data)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)
	{ }
};
template<class T, class Ref, class Ptr>
struct RBTreeIterator//struct 因为你这个肯定要给外面的用，就是，比较公有，
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T, Ref, Ptr> Self;
	//成员：两个指针,
	Node* _node;
	Node* _root;
	//默认构造
	RBTreeIterator(Node* node,Node* root)
		:_node(node)
		,_root(root)
	{ }
	/*RBTreeIterator& operator++()
	{
	
		Node* cur = _node;
		Node* parent = cur->_parent;
		if (cur->_right)
		{
			while (cur->_left)
			{
				cur = cur->_left;
			}
			return RBTreeIterator(cur);
		}
		else if (parent->_left == cur)
			return RBTreeIterator(parent);
		else if (parent->_right == cur)
		{
			while (parent && parent->_right == cur)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			return RBTreeIterator(parent);
		}
		else assert(false);



	}*/
	Self& operator++()
	{
		assert(_node);
		Node* cur = _node;
		Node* parent = cur->_parent;
		if (cur->_right)//如果右孩子不为空，访问右孩子的最小节点，即最左孩子
		{
			cur = cur->_right;
			while (cur->_left)
			{
				cur = cur->_left;
			}
			_node = cur;
		}
		else//找到/访问孩子是父亲的左孩子的父亲
		{
			while (parent && parent->_right == cur)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;


	}
	Self& operator--()
	{
		Node* cur = _node;
		
		if (cur == nullptr)
		{
			Node* ccur = _root;
			while (ccur&&ccur->_right)
			{
				ccur = ccur->_right;
			}
			_node = ccur;
		}
		else
		{
			Node* parent = cur->_parent;
			if (cur->_left)//左边不为空，左边找最右节点
			{
				cur = cur->_left;
				while (cur->_right)
				{
					cur = cur->_right;
				}
				_node = cur;
			}
			else
			{
				//如果孩子是父亲的右孩子，那就是访问完了的,要找的就是这个
				while (parent && parent->_left == cur)
				{
					cur = parent;
					parent = parent->_parent;
				}
				_node = parent;
			}
			
		}
		return *this;
	}
	//Self& operator--()
	//{
	//	Node* cur = _node;

	//	if (cur == nullptr)
	//	{
	//		// --end()
	//		cur = _root;

	//		while (cur && cur->_right)
	//		{
	//			cur = cur->_right;
	//		}

	//		_node = cur;
	//	}
	//	else
	//	{
	//		Node* parent = cur->_parent;

	//		if (cur->_left)
	//		{
	//			// 左子树最大节点
	//			cur = cur->_left;

	//			while (cur->_right)
	//			{
	//				cur = cur->_right;
	//			}

	//			_node = cur;
	//		}
	//		else
	//		{
	//			// 往上找：当前节点是父亲右孩子的祖先

	//			while (parent && cur == parent->_left)
	//			{
	//				cur = parent;
	//				parent = parent->_parent;
	//			}

	//			_node = parent;
	//		}
	//	}

	//	return *this;
	//}
	//Self operator--()
	//{
	//	if (_node == nullptr)  // --end()
	//	{
	//		// --end()，特殊处理，走到中序最后一个结点，整棵树的最右结点
	//		Node* rightMost = _root;
	//		while (rightMost && rightMost->_right)
	//		{
	//			rightMost = rightMost->_right;
	//		}
	//		_node = rightMost;
	//	}
	//	else if (_node->_left)
	//	{
	//		// 左子树不为空，中序左子树最后一个
	//		Node* rightMost = _node->_left;
	//		while (rightMost->_right)
	//		{
	//			rightMost = rightMost->_right;
	//		}
	//		_node = rightMost;
	//	}
	//	else
	//	{
	//		// 孩子是父亲右的那个祖先
	//		Node* cur = _node;
	//		Node* parent = cur->_parent;
	//		while (parent && cur == parent->_left)
	//		{
	//			cur = parent;
	//			parent = cur->_parent;
	//		}
	//		_node = parent;
	//	}

	//	return *this;
	//}
	Ref operator*()
	{
		return _node->_data;
	}
	Ptr operator->()
	{
		return &_node->_data;//it->要达到的效果就是，it->可以访问到data里面的东西，那就要返回_node->_data;的地址
	}
	bool operator==(const RBTreeIterator& it)const//一般只读属性的就要加const
	{
		return _node == it._node;
	}
	bool operator!=(const RBTreeIterator& it)const
	{
		return _node != it._node;
	}
};
template<class K, class	T ,class keyoftree>
class RBTree
{
	//typedef RBTreeNode<K,T> Node;当然可以这么设计，但是 STL 选择存 T，是为了让底层 RBTree 更通用。
	typedef RBTreeNode<T> Node;

public:
	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> Const_Iterator;//加 const 是为了兼容返回值为 const 类型的函数，T不加 const 是因为RBTreeIterator里面没有返回 const T 的函数
	Iterator begin()
	{
		Node* cur = _root;
		if (_root == nullptr)
			return Iterator(nullptr,_root);
		while (cur&&cur->_left)
		{
			cur = cur->_left;
		}
		return Iterator(cur,_root);
	}
	Const_Iterator begin()const
	{
		Node* cur = _root;
		if (_root == nullptr)
			return Iterator(nullptr,_root);
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return Const_Iterator(cur, _root);
	}
	Iterator end()
	{
		return Iterator(nullptr, _root);
	}
	Const_Iterator end()const
	{
		
		return Const_Iterator(nullptr, _root);
	}

	// 插入
	pair<Iterator,bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return { Iterator(_root,_root),true };
		}
		//依旧先找到插入位置
		keyoftree kof;
		Node* cur = _root;
		Node* parent = _root;
		while (cur)
		{
			if (kof(data) < kof(cur->_data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kof(data) > kof(cur->_data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return { Iterator(cur,_root),false };
		}
		cur = new Node(data);
		Node* newnode = cur;
		if (kof(data) < kof(parent->_data))
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else if (kof(data) > kof(parent->_data))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
			assert(false);
		while (parent&&parent->_col==RED)//父亲为红
		{
			Node* grandfather = parent->_parent;
			Node* uncle = nullptr;
			if (parent == grandfather->_left)//父亲是爷爷的左孩子
			{
				uncle = grandfather->_right;//得到叔叔
					if (uncle && uncle->_col == RED)//叔叔存在且为红
					{
						//仅变色
						grandfather->_col = RED;
						uncle->_col = BLACK;
						parent->_col = BLACK;
					}
					else if (parent->_left == cur) // 叔叔不存在或为黑，然后有分，我和父亲的关系和父亲和爷爷的关系是一样的，都是左孩子
					{
						//右单旋
						RotateR(grandfather);
						//变色
						parent->_col = BLACK;
						grandfather->_col = RED;
						break;
					}
					else if (parent->_right == cur)//我c是父亲p的右孩子，双旋
					{
						//左右双旋
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
						break;
					}
					else
						assert(false);
				
			}
			else if (parent == grandfather->_right)
			{
				uncle = grandfather->_left;
				
					if (uncle && uncle->_col == RED)
					{
						//仅变色
						grandfather->_col = RED;
						uncle->_col = BLACK;
						parent->_col = BLACK;
					}
					else if (parent->_right == cur)//uncle存在与否已经不重要了
					{
						//左单旋
						RotateL(grandfather);
						//变色
						parent->_col = BLACK;
						grandfather->_col = RED;
						break;
					}
					else if (parent->_left == cur)
					{
						//右左双旋
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
						break;
					}
					else
						assert(false);
			}
			else
				assert(false);
			//继续更新
			cur = grandfather;
			parent = cur->_parent;
		}
		//根一定是黑，最后统一处理，
		_root->_col = BLACK;
		return { Iterator(newnode,_root),true };

	}
	

	// 右旋
	void RotateR(Node* parent)
	{
		Node* sub = parent;
		Node* subL = parent->_left;
		Node* pparent = parent->_parent;
		Node* subLR = subL->_right;
		sub->_left = subLR;
		if (subLR)subLR->_parent = sub;
		subL->_right = sub;
		sub->_parent = subL;
		if (pparent == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else if (pparent->_left == sub)
		{
			pparent->_left = subL;
			subL->_parent = pparent;
		}
		else if (pparent->_right == sub)
		{
			pparent->_right = subL;
			subL->_parent = pparent;
		}
		else
			assert(false);
	}


	// 左旋
	void RotateL(Node* parent)
	{
		Node* sub = parent;
		Node* subR = parent->_right;
		Node* pparent = parent->_parent;
		Node* subRL = subR->_left;
		sub->_right = subRL;
		if (subRL) subRL->_parent = sub;
		subR->_left = sub;
		sub->_parent = subR;
		if (pparent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else if (pparent->_left == sub)
		{
			pparent->_left = subR;
			subR->_parent = pparent;
		}
		else if (pparent->_right == sub)
		{
			pparent->_right = subR;
			subR->_parent = pparent;
		}
		else
			assert(false);
	}


	// 获取树高度
	int Height()
	{
		return _Height(_root);
	}


	// 获取节点数量
	int Size()
	{
		return _Size(_root);
	}


	// 查找
	Node* Find(const T& data)
	{
		if (_root == nullptr)return nullptr;
		Node* cur = _root;
		keyoftree kof;
		while (cur)
		{
			if (kof(data) <kof( cur->_data))
				cur = cur->_left;
			else if (kof( data) > kof( cur->_data))
				cur = cur->_right;
			else return cur;
		}
		return nullptr;
	}

	
private:


	// 高度辅助函数
	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left_hegint = _Height(root->_left);
		int right_height = _Height(root->_right);
		return max(left_hegint, right_height) + 1;
	}


	// 节点数量辅助函数
	int _Size(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = _Size(root->_left);
		int right = _Size(root->_right);
		return left + right + 1;
	}



private:

	Node* _root = nullptr;
};