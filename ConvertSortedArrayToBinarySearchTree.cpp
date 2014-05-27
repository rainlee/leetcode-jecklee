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
 * 取中点作为根
 * 分别处理左右子树
 ***/
class Solution {
public:
    TreeNode *SA2BST(vector<int> &num, int low, int high)
    {
        if (low > high)
            return NULL;
        
        int mid = low + (high - low)/2;
        TreeNode *root = new TreeNode(num[mid]);
        
        root->left = SA2BST(num, low, mid-1);
        root->right = SA2BST(num, mid+1, high);
        
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (0 == num.size())
            return NULL;
        
        return SA2BST(num, 0, num.size()-1);
    }
};