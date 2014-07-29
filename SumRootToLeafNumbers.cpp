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
 * 先序遍历，累计求和，直到叶子节点
 ***/
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return sumRoot2Leaf(root, 0);
    }
private:
    int sumRoot2Leaf(TreeNode *root, int pathsum)
    {
        if (NULL == root)
            return 0;
        pathsum = pathsum * 10 + root->val;   // sum
        
        if (!root->left && !root->right)  // leaf node
            return pathsum;
            
        return sumRoot2Leaf(root->left, pathsum) + sumRoot2Leaf(root->right, pathsum);
    }
};