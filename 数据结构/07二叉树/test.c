#include <stdio.h>
#include "BinaryTree.h"

int main()
{
	int i = 0;
	char str[] = { "ABD##E#H##CF##G##" };
	int n = strlen(str);
	BTNode* tree=BinaryTreeCreate(str, n, &i);
	BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreeInOrder(tree);
	printf("\n");
	BinaryTreePostOrder(tree);
	printf("\n");
	printf("%d\n",BinaryTreeSize(tree));
	printf("%d\n", BinaryTreeLeafSize(tree));
	printf("%d\n", BinaryTreeLevelKSize(tree, 3));
}