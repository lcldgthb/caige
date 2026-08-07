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


template<class K, class V>
struct RBTreeNode
{
	pair<K, V> _kv;

	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)
	{ }
};


template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;

public:

	// 插入
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		//依旧先找到插入位置
		Node* cur = _root;
		Node* parent = _root;
		while (cur)
		{
			if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		cur = new Node(kv);
		//还是要根据kv来比！！！！，第三次犯这个错误了！！！
		/*if (parent->_left == cur)
		{
			parent->_left = new Node(kv);
		}
		else if (parent->_right == cur)
			parent->_right = new Node(kv);
		else assert(false);*/
		if (kv.first < parent->_kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else if (kv.first > parent->_kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
			assert(false);
		//更新颜色
		//情况一：父亲是黑是，不用处理
		//情况二：父亲是红色
		//1，叔叔存在，也是红色
		//2，叔叔不存在，或者是黑色
		//2.1单旋+变色
		//2.2双旋+变色
	
		while (parent&&parent->_col==RED)
		{
			Node* grandfather = parent->_parent;
			Node* uncle = nullptr;
			if (parent == grandfather->_left)
			{
				uncle = grandfather->_right;
					if (uncle && uncle->_col == RED)
					{
						//仅变色
						grandfather->_col = RED;
						uncle->_col = BLACK;
						parent->_col = BLACK;
					}
					else if (parent->_left == cur)//uncle存在与否已经不重要了
					{
						//右单旋
						RotateR(grandfather);
						//变色
						parent->_col = BLACK;
						grandfather->_col = RED;
						break;
					}
					else if (parent->_right == cur)
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
		return true;

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


	// 中序遍历
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
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
	Node* Find(const K& key)
	{
		if (_root == nullptr)return nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_kv.first)
				cur = cur->_left;
			else if (key > cur->_kv.first)
				cur = cur->_right;
			else return cur;
		}
		return nullptr;
	}


	// 检查红黑树是否平衡
	bool IsBalance()
	{
		if (_root == nullptr)return true;
		Node* cur = _root;
		int refnum = 0;
		while (cur)
		{
			if (cur->_col == BLACK)
				refnum++;
			cur = cur->_left;
		}
		return Check(_root, 0, refnum);
	}


private:

	// 检查红黑树性质
	bool Check(Node* root, int blackNum, const int refNum)
	{
		//满足四条规则：
		//1,2，肯定不用看，
		//3，所有的红节点的父亲是不是红色
		//4，路径黑色是不是一样多
		//前序遍历
		if (root == nullptr)
		{
			if (blackNum != refNum)
				return false;
			else
				return true;
		}
		if (root->_col == BLACK)blackNum++;
		if (root->_col == RED)
		{
			if (root->_parent&&root->_parent->_col == RED)
				return false;
			else if (root->_parent == nullptr)
			{
				if (root->_col == RED)
				{
					cout << "根节点为红色！！" << endl;
					return false;
				}
			}
		}
		
		return Check(root->_left,blackNum,refNum) && Check(root->_right, blackNum, refNum);
	}


	// 中序遍历辅助函数
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << " ";
		_InOrder(root->_right);
	}


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