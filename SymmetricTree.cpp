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
 * 先比较 左孩子 与 右孩子
 * 再比较 左孩子的左子树与右孩子的右子树
 * 以及 左孩子的右子树与右孩子的左子树
 ***/
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (NULL == root)
            return true;
        
        return isSymLR(root->left, root->right);
    }
    
private:
    bool isSymLR(TreeNode *pleft, TreeNode *pright)
    {
        if (!pleft && !pright)
            return true;
        if ((pleft && !pright) || (!pleft && pright))
            return false;
        
        return (pleft->val == pright->val) && isSymLR(pleft->left, pright->right) && isSymLR(pleft->right, pright->left);
        
    }
};