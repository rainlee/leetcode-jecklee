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
 * �Ӹ���Ҷ�ӣ��������
 * �ۼ�·���ϵĺͣ�����Ҷ�ӽڵ㣬ǡ��·���͵���sum�����ҵ�
 * �ҵ�����һ���򷵻�true�����ü������ˣ�
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