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