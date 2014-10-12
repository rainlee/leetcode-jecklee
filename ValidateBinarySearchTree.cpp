/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/***
 * 二叉查找树
 * 根节点大于左子树，小于右子树
 * 递归函数记录左右边界，分别对根节点和左右子树进行判断
 ***/
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return visitBST(root, INT_MIN, INT_MAX);
    }
private:
    bool visitBST(TreeNode *root, int low, int high)
    {
        if (NULL == root)
            return true;
        
        return (root->val > low) && (root->val < high) &&
               visitBST(root->left, low, root->val) &&
               visitBST(root->right, root->val, high);      // update the bound
    }
};

/***
 * 中序遍历，递增序列
 * 记录上一个节点
 ***/
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        int last = INT_MIN;
        return inorder(root, last);
    }
private:
    bool inorder(TreeNode *root, int &last) {
        if (!root) return true;
        if (!inorder(root->left, last))
            return false;
        if (root->val <= last)
            return false;
        last = root->val;
        return inorder(root->right, last);
    }
};