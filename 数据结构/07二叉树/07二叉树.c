#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(DataType* a, int n, int* pi)
{
	//判断当前结点是否为空，若为空结点则返回NULL
	if (a[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}
	//当前结点非空，创建当前结点
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->data = a[*pi];
	//字符位置向后移动一个位置
	(*pi)++;
	//创建左子树
	root->left = BinaryTreeCreate(a, n, pi);
	//创建右子树
	root->right = BinaryTreeCreate(a, n, pi);
	return root;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	//如果树不为空
	if (*root)
	{
		//销毁左子树
		BinaryTreeDestory(&(*root)->left);
		//销毁右子树
		BinaryTreeDestory(&(*root)->right);
		//释放结点
		free(*root);
		//置空
		*root = NULL;
	}
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	//当树为空时，结点个数为0，否则为根结点个数 加上根的左子树中结点个数
	//再加上根的右子树结点个数
	int count = 0;
	if (root)
	{
		count = 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
	}
	else
	{
		return 0;
	}
	return count;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	//当树为空时，叶子结点个数为0
	//当某个结点的左右子树均为空时，此结点是叶子结点，返回1
	int count = 0;
	if (!root)
	{
		return 0;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		count = BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
	}
	return count;
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//如果树为空或者K小于等于0，返回0
	if (root == NULL || k <= 0)
	{
		return 0;
	}
	//树不为空且K等于1，返回1
	if (root != NULL && k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, DataType x)
{
	//当前结点是否为空
	if (!root)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	//当前结点不为空也不等于x,遍历左子树
	BTNode* tmp = BinaryTreeFind(root->left, x);
	if (!tmp)
	{
		return tmp;
	}
	else
	{
		//左子树返回空，遍历右子树
		return tmp = BinaryTreeFind(root->right, x);
	}
}
// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	//如果树不为空
	if (root)
	{
		//访问根结点
		putchar(root->data);
		//遍历左子树
		BinaryTreePrevOrder(root->left);
		//遍历右子树
		BinaryTreePrevOrder(root->right);
	}
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	//如果树不为空
	if (root)
	{
		//中序遍历根节点的左子树
		BinaryTreeInOrder(root->left);
		//访问根结点
		putchar(root->data);
		//中序遍历右子树
		BinaryTreeInOrder(root->right);
	}
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		//遍历左子树
		BinaryTreePostOrder(root->left);
		//遍历右子树
		BinaryTreePostOrder(root->right);
		//访问根结点
		putchar(root->data);
	}
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{

}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{

}