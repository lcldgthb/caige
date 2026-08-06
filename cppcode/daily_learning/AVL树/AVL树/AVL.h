#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
template<class K, class V>
struct AVLTreeNode
{
	// 需要parent指针，后续更新平衡因子可以看到
	pair<K, V> _kv;

	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf; // balance factor，平衡因子，右高度-左高度

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{
	}
};


template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:

	// 插入
	bool Insert(const pair<K, V>& kv)
	{
		//插入已经有的值就会返回false
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent= nullptr;
		while (cur)
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (kv.first>parent->_kv.first)
		{
			parent->_right = cur;
			parent->_bf++;
		}
		else if (kv.first < parent->_kv.first)
		{
			parent->_left = cur;
			parent->_bf--;
		}
		else
		{
			assert(false);//防御性编程，理论上不可能走到这里
		}
		cur->_parent = parent;
		cur->_bf = 0;
		//更新平衡因子
		// 根据父母的平衡因子来移动
		//0,不用动
		//1，-1，不管是1还是-1，肯定是0变过来的，然后，肯定该子树的高度+1了，所以，看父母是父母的左孩子还是右孩子
		while (parent)
		{
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
				if (parent == nullptr)break;//爷爷为空，那么就是到根节点了，直接break
				if (parent->_left == cur)
				{
					parent->_bf--;
				}
				else if (parent->_right == cur)
				{
					parent->_bf++;
				}
				else
					assert(false);
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//旋转
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
					//旋转后，不用向上更新了，
					break;
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent); break;
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent); break;
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent); break;
				}
				else
					assert(false);

			}
			else
				assert(false);
		}
		return true;
	}

	//所有旋转的情景是，元素已经插入，然后，超级不平衡，即parent的平衡因子=2/-2
	// 右单旋
	void RotateR(Node* parent)
	{
		//注意为空的几种情况
		// pParent为空
		// subLR 为空
		//
		Node* pParent = parent->_parent;
		Node* sub = parent;
		Node* subL = sub->_left;
		Node* subLR = subL->_right;
		sub->_left = subLR;
		if(subLR)//subLR可能为空，要特判
		subLR->_parent = sub;
		subL->_right = sub;
		sub->_parent = subL;
		if (pParent == nullptr)
		{
			_root = subL;
			//parent也要更新！！！
			subL->_parent = nullptr;
		}
		else if (pParent->_left == sub)
		{
			pParent->_left = subL;
			subL->_parent = pParent;//别忘了更新parent
		}
		else if (pParent->_right == sub)
		{
			pParent->_right = subL;
			subL->_parent = pParent;
		}
		else
			assert(false);
		//平衡因子更新
		subL->_bf = 0;
		sub->_bf = 0;
	}


	// 左单旋
	void RotateL(Node* parent)
	{
		Node* pparent = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (pparent == nullptr)
		{
			_root = subR;
			//parent也要更新！！！
			subR->_parent = nullptr;
		}
		else if (pparent->_left == parent)
		{
			pparent->_left = subR;
			subR->_parent = pparent;
		}
		else if (pparent->_right == parent)
		{
			pparent->_right = subR;
			subR->_parent = pparent;
		}
		else
			assert(false);
		//更新平衡因子
		parent->_bf = 0;
		subR->_bf = 0;
	}


	// 左右双旋，即先左旋在右旋
	void RotateLR(Node* parent)
	{
		Node* sub = parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;//先存储一下，
		RotateL(subL);
		RotateR(sub);
		//更新平衡因子
		//subLR->_bf = 0;//这个节点成为新的根了，那么，肯定是0
		//其他两个，要根据插入节点是subLR的左右节点来判断
		//不能再rotate后根据平衡因子判断，因为这里已经变了！！！！！！！！
		// if (subLR->_bf == -1)//也就是插入图示里面的e，也就是8的左边
		if (bf == -1)//也就是插入图示里面的e，也就是8的左边
		{
			sub->_bf=  1;
			subL->_bf = 0;
		}
		else if (bf == 1)
		{
			sub->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == 0)
		{
			sub->_bf = 0;
			subL->_bf = 0;
		}
		else
			assert(false);

		subLR->_bf = 0;//因为要以它为依据判断，所以，后更新

	}
	void RotateRL(Node* sub)
	{
		Node* subR = sub->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(sub);
		// 更新平衡因子
		if (bf == 0)
		{
			sub->_bf = 0;
			subR->_bf = 0;
		}
		else if (bf == 1)       // 新节点插入在 subRL 的右边
		{
			sub->_bf = -1;      // sub 变成了左子树，没有右孩子
			subR->_bf = 0;      // subR 左右平衡
		}
		else if (bf == -1)      // 新节点插入在 subRL 的左边
		{
			sub->_bf = 0;       // sub 左右平衡
			subR->_bf = 1;      // subR 只有右孩子
		}
		else
			assert(false);
		subRL->_bf = 0;
	}

	//// 右左双旋，即先右旋再左旋
	////void RotateRL(Node* parent)
	//void RotateRL(Node* sub)
	//{
	//	Node* subR = sub->_right;
	//	Node* subRL = subR->_left;
	//	int bf = subRL->_bf;
	//	RotateR(subR);
	//	RotateL(sub);
	//	//更新平衡因子
	//	if (bf == 0)
	//	{
	//		sub->_bf = 0;
	//		subR->_bf = 0;
	//	}
	//	else if (bf == 1)
	//	{
	//		sub->_bf = 0;
	//		subR->_bf = -1;
	//	}
	//	else if (bf == -1)
	//	{
	//		sub->_bf = 1;
	//		subR->_bf = 0;
	//	}
	//	else
	//		assert(false);
	//	subRL->_bf = 0;
	//}


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


	// 判断是否为AVL树
	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
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
			else
				return cur;
		}
		return nullptr;
	}



private:

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
		return max(left_hegint , right_height) + 1;
	}


	// 节点数量辅助函数
	int _Size(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left= _Size(root->_left);
		int right = _Size(root->_right);
		return left + right + 1;
	}


	// 平衡检测辅助函数
	bool _IsBalanceTree(Node* root)
	{
		if (root == nullptr)return true;
		int left_height =_Height(root->_left);
		int right_height = _Height(root->_right);
		int bf = right_height - left_height;
		if (_IsBalanceTree(root->_left) && _IsBalanceTree(root->_right) && bf<2 && bf>-2)
		{
			//还要判断平衡因子
			if (root->_bf!= bf)
			{
				cout << "平衡因子错误：" << endl;
				return false;
			}
			return true;
		}
		return false;
	}



private:

	Node* _root = nullptr;

};