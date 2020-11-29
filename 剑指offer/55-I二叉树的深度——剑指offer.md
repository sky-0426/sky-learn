# 剑指offer55-I.二叉树的深度

## 题目描述

输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：

给定二叉树 [3,9,20,null,null,15,7]，
返回它的最大深度 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof

## 解题思路

- 递归法解决(后序遍历)
- 如果节点为空的话，返回0表示当前深度为0
- 先求左子树的深度，再求右子树的深度，取左子树和右子树深度的最大值载加一(+1是要算上当前节点)

## 代码实现

```cpp
class Solution {
public:
    int getDepth(TreeNode* node)
    {
        if(node==NULL)
        {
            return 0;
        }
        int lefedepth=getDepth(node->left);
        int rightdepth=getDepth(node->right);
        int depth=max(lefedepth,rightdepth)+1;
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};
```

