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
 * 从根到叶子，先序遍历
 * 累计路径上的和，若到叶子节点，恰好路径和等于sum，则找到
 * 找到任意一条则返回true（不用继续找了）
 ***/
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (NULL == root)
            return false;
        
        if ((NULL == root->left) && (NULL == root->right))  // leaf node
            return (sum == root->val);
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};