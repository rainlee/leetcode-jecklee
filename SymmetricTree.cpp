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
 * �ݹ�
 * �ȱȽ� ���� �� �Һ���
 * �ٱȽ� ���ӵ����������Һ��ӵ�������
 * �Լ� ���ӵ����������Һ��ӵ�������
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