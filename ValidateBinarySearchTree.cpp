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
 * ���������
 * ���ڵ������������С��������
 * �ݹ麯����¼���ұ߽磬�ֱ�Ը��ڵ���������������ж�
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