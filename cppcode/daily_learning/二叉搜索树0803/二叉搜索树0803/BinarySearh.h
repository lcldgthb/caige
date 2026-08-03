#pragma once
#pragma once
#include<iostream>
using namespace std;
namespace caige
{

namespace key
{
	template<class K>
	struct BSTNode
	{
		K _key;
		BSTNode<K>* _left;
		BSTNode<K>* _right;

		BSTNode(const K& key)
			:_key(key)
			, _left(nullptr)
			, _right(nullptr)
		{
		}
	};


	template<class K>
	class BSTree
	{
		using Node = BSTNode<K>;

	public:
		//让编译器生成默认构造，因为下面已经实现了拷贝构造，编译器默认不生成，所以，这里要让编译器生成默认构造
		BSTree() = default;
		/*上面那句，效果等于：BSTree()
			:_root(nullptr)
		{ };*/

		// 拷贝构造（可选实现）
		BSTree(const BSTree& t)
		{
			_root = Copy(t);
		}
	//Node*  _BSTree(BSTree& tmp; const BSTree& t)
	//	{
	//		//前序递归构造

	//	}


		// 析构函数
	~BSTree()
	{
		Destroy(_root);
	}

	
		// 插入，判断插入是否成功即可
		bool Insert(const K& key)
		{
			Node* newnode = new Node(key);
			if (_root == nullptr)
			{
				_root = newnode;
				return true;
			}
			//肯定要先找到你要插入的位置，肯定是插入到叶子节点
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				parent = cur;
				//if (key < cur->_key)保证parent和cur是链接起来的
				if (key < parent->_key)
				{
					cur = parent->_left;
				}
				else if (key > parent->_key)
				{
					cur = parent->_right;
				}
				else
				{				
					//return false;防止内存泄露
					delete newnode;
					return false;
				}
			}
		//找到了插入位置
			//cur = newnode;
			if (key < parent->_key)parent->_left = newnode;
			if (key > parent->_key)parent->_right = newnode;
			return true;
		}


		// 查找,找到在不在即可
		bool Find(const K& key)
		{
			if (_root == nullptr)return false;
			Node* cur = _root;
			while (cur)
			{
				if (key < cur->_key)
					cur = cur->_left;
				else if (key > cur->_key)
					cur = cur->_right;
				else return true;
			}
			return false;
		}


		//// 删除
		//bool Erase(const K& key)
		//{
		//	if (_root == nullptr)return false;
		//	//根节点单独处理
		//	if (_root->_key == key)
		//	{
		//		if (_root->_left == nullptr)
		//		{
		//			Node* tmp = _root;
		//			_root = _root->_right;
		//			delete tmp;
		//			return true;
		//		}
		//		else if (_root->_right == nullptr)
		//		{
		//			Node* tmp = _root;
		//			_root = _root->_left;
		//			delete tmp;
		//			return true;
		//		}
		//	}
		//	//难点
		//	//先找到要删除的节点的位置，
		//	//节点位置有两种情况，
		//	//1，至少有一边没有孩子，那么就把另一边链接给父亲即可
		//	// 2，该节点左右都有孩子——交换删除法
		//	//先找到该节点
		//	Node* targetnode = nullptr;
		//	Node* cur = _root;
		//	//Node* curparent = nullptr;//非常关键啊
		//	//Node* curparent = cur;//非常关键啊
		//	//while (cur)
		//	//{
		//	//	curparent = cur;
		//	//	if (key < cur->_key)
		//	//		cur = cur->_left;
		//	//	else if (key > cur->_key)
		//	//		cur = cur->_right;
		//	//	else 
		//	//	{
		//	//		targetnode = cur;
		//	//		break;
		//	//	}
		//	//}
		//	//没有判断是否找到！
		//	Node* curparent = cur;
		//	while (cur)
		//	{
		//		
		//		if (key < cur->_key)
		//		{
		//			curparent = cur;
		//			cur = cur->_left;
		//		}
		//		else if (key > cur->_key)
		//		{
		//			curparent = cur;
		//			cur = cur->_right;
		//		}
		//		else
		//		{
		//			targetnode = cur;
		//			break;
		//		}
		//	}
		//	//if (targetnode != cur)return false;不能这么写
		//	if (targetnode ==nullptr)return false;
		//	//先处理第一种情况;
		//	/*if (curparent->_left == targetnode)
		//	{
		//		if (targetnode->_left == nullptr)
		//			curparent->_left = targetnode->_right;
		//		else
		//			curparent->_left = targetnode->_left;
		//	}不能这么写*/
		//	if (targetnode->_left == nullptr)
		//	{
		//		if (curparent->_left == targetnode)
		//		{
		//			curparent->_left = targetnode->_right;
		//		}
		//		else
		//			curparent->_right = targetnode->_right;
		//		delete targetnode;
		//		return true;
		//	}
		//	else if(targetnode->_right==nullptr)
		//	{
		//		if (curparent->_left == targetnode)
		//		{
		//			curparent->_left = targetnode->_left;
		//		}
		//		else
		//			curparent->_right = targetnode->_left;
		//		delete targetnode;
		//		return true;
		//	}
		//	else //左右都不为空，第二种情况
		//	{
		//		//找到左边最大的那个节点或者右边最小的节点
		//		//左边最大也就是左边最靠右的节点，
		//		//右边最小，也就是右边最靠左的节点
		//		//我这里找右子树里面最靠左的节点
		//		//Node* swapnode = targetnode;
		//		Node* swapnode = targetnode->_right;
		//		Node* swapnodeparent = swapnode;
		//			while (swapnode->_left)
		//			{
		//				swapnodeparent = swapnode;
		//				swapnode = swapnode->_left;
		//			}
		//			//找到了，先赋值
		//			targetnode->_key = swapnode->_key;
		//			//删除
		//			//swapnodeparent->_left = swapnode->_right;
		//			//虽然是去右子树里面找最左边的节点，但是不要以为全都是往左走所以swapnode一定是他父母的左节点，有一个特殊情况，就是，第一步，第一步他去右子树里面找，他就是先往右走
		//			if (swapnodeparent->_left == swapnode)
		//				swapnodeparent->_left = swapnode->_right;
		//			else//swapnodeparent.right==swapnode
		//				swapnodeparent->_right = swapnode->_right;
		//			delete swapnode;
		//			return true;
		//	}
		//}
//// 删除
//bool Erase(const K& key)
//{
//	if (_root == nullptr)
//		return false;
//
//
//	// 找删除节点以及父节点
//	Node* parent = nullptr;
//	Node* cur = _root;
//
//
//	while (cur)
//	{
//		if (key < cur->_key)
//		{
//			parent = cur;
//			cur = cur->_left;
//		}
//		else if (key > cur->_key)
//		{
//			parent = cur;
//			cur = cur->_right;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//
//	// 没找到
//	if (cur == nullptr)
//		return false;
//
//
//
//	// 情况1：左右孩子都存在
//	// 找右子树最小节点替换
//	if (cur->_left && cur->_right)
//	{
//		Node* replaceParent = cur;
//		Node* replace = cur->_right;
//
//
//		// 找右子树最小节点
//		while (replace->_left)
//		{
//			replaceParent = replace;
//			replace = replace->_left;
//		}
//
//
//		// 替换数据
//		cur->_key = replace->_key;
//
//
//		// 删除替代节点
//		if (replaceParent->_left == replace)
//		{
//			replaceParent->_left = replace->_right;
//		}
//		else
//		{
//			replaceParent->_right = replace->_right;
//		}
//
//
//		delete replace;
//	}
//	else
//	{
//		// 情况2：只有一个孩子或者没有孩子
//
//		Node* child = nullptr;
//
//
//		if (cur->_left)
//			child = cur->_left;
//		else
//			child = cur->_right;
//
//
//		// 删除的是根节点
//		if (cur == _root)
//		{
//			_root = child;
//		}
//		else
//		{
//			// 删除普通节点
//			if (parent->_left == cur)
//			{
//				parent->_left = child;
//			}
//			else
//			{
//				parent->_right = child;
//			}
//		}
//
//
//		delete cur;
//	}
//
//
//	return true;
//}
bool Erase(const K& key)
{
	if (_root == nullptr)
		return false;

	// 根节点单独处理（只有一个孩子或为空）
	if (_root->_key == key)
	{
		if (_root->_left == nullptr)
		{
			Node* tmp = _root;
			_root = _root->_right;
			delete tmp;
			return true;
		}
		else if (_root->_right == nullptr)
		{
			Node* tmp = _root;
			_root = _root->_left;
			delete tmp;
			return true;
		}
	}

	// 找到待删除节点及其父节点
	Node* targetnode = nullptr;
	Node* cur = _root;
	Node* curparent = cur;

	while (cur)
	{
		if (key < cur->_key)
		{
			curparent = cur;
			cur = cur->_left;
		}
		else if (key > cur->_key)
		{
			curparent = cur;
			cur = cur->_right;
		}
		else
		{
			targetnode = cur;
			break;
		}
	}

	if (targetnode == nullptr)
		return false;


	// 情况1：删除节点左为空
	if (targetnode->_left == nullptr)
	{
		if (curparent->_left == targetnode)
		{
			curparent->_left = targetnode->_right;
		}
		else
		{
			curparent->_right = targetnode->_right;
		}

		delete targetnode;
		return true;
	}

	// 情况2：删除节点右为空
	else if (targetnode->_right == nullptr)
	{
		if (curparent->_left == targetnode)
		{
			curparent->_left = targetnode->_left;
		}
		else
		{
			curparent->_right = targetnode->_left;
		}

		delete targetnode;
		return true;
	}

	// 情况3：左右都不为空，使用替换删除法
	else
	{
		// 找右子树最小节点（后继）
		Node* swapnode = targetnode->_right;
		Node* swapnodeparent = targetnode;

		while (swapnode->_left)
		{
			swapnodeparent = swapnode;
			swapnode = swapnode->_left;
		}

		// 替换数据
		targetnode->_key = swapnode->_key;


		// 删除替代节点
		if (swapnodeparent->_left == swapnode)
		{
			swapnodeparent->_left = swapnode->_right;
		}
		else
		{
			swapnodeparent->_right = swapnode->_right;
		}

		delete swapnode;
		return true;
	}
}
		//总结这次实现二叉搜索树的删除接口时犯的错误如下：
		// ⭐ 第一：父节点必须在 cur 移动之前保存。
		//	⭐ 第二：找右子树最小节点时，虽然搜索路径是“向左”，但它第一次可能是从父节点向右走，所以替代节点不一定是父节点左孩子。
		// 中序遍历,由于不想让外面拿到根节点，但是，中序遍历又必须要用到根节点，所以，采用这种嵌套的形式
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}


	private:

		// 中序遍历递归实现
		void _InOrder(Node* root)
		{
			if (root == nullptr)return;
			_InOrder(root->_left);
			cout << root->_key<< " ";
			_InOrder(root->_right);
		}


		// 销毁树
		void Destroy(Node* root)
		{
			//后序遍历销毁
			if (root == nullptr)
				return;
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
			//root = nullptr;这里是值传递，所以这一句没有效果，外面的根节点不会变
		}


		// 拷贝树
		Node* Copy(Node* root)
		{
			if (root == nullptr)return;
			//前序遍历拷贝
			//Node* ret = nullptr;
			Node* ret = new Node(root->_key);
			ret->_left = Copy(root->_left);
			ret->_right = Copy(root->_right);
			return ret;
		}
	private:

		Node* _root = nullptr;
	};
}
}