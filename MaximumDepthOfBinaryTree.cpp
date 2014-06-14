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
 * 递归
 * 分别求左右子树的深度
 ***/
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (NULL == root)
            return 0;
        
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};