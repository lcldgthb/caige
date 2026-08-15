#include<iostream>
#include<vector>
using namespace std;
typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
} treenode;
void preorder(treenode*root)
{
    if(root==NULL)
    return ;
    //访问根节点
    //例如：cout<<root->val<<endl;
    cout<<root->val<<endl;
    //访问左子树
    preorder(root->left);
    //访问右子树
    preorder(root->right);
}
void inorder(treenode*root)
{
    if(root==NULL)
    return ;
    //访问左子树
    inorder(root->left);
    //访问根节点
    cout<<root->val<<endl;
    //访问右子树
    inorder(root->right);
}
void postorder(treenode*root)
{
    if(root==NULL)
    return ;
    //访问左子树
    postorder(root->left);
    //访问右子树
    postorder(root->right);
    //访问根节点
    cout<<root->val<<endl;
}
int main()
{

    return 0;
}