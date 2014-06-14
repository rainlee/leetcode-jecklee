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
 * ��1���ݹ������Ȼ��Ƚ���������
 * ���ݹ�ֱ��ж���������
 * ȱ�㣺���ظ�������
 ***/
/*
class Solution {
public:
    int treeDepth(TreeNode *root)
    {
        if (NULL == root)
            return 0;
        
        return max(treeDepth(root->left), treeDepth(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode *root) {
        if (NULL == root)
            return true;
        
        int depl = treeDepth(root->left);
        int depr = treeDepth(root->right);
        int diff = abs(depl - depr);
        if (diff > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
*/

/***
 * ��2��һ�߱��������һ���ж��Ƿ�ƽ��
 ***/
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int dep;
        return treeDepth(root, dep);
    }
    
    bool treeDepth(TreeNode *root, int &dep)
    {
        if (NULL == root)
        {
            dep = 0;
            return true;
        }
        
        int depl, depr;
        
        if (!treeDepth(root->left, depl) || !treeDepth(root->right, depr))  // check children
            return false;
        
        int diff = abs(depl - depr);
        if (diff > 1)
            return false;
        
        dep = max(depl, depr) + 1;  // cal dep
        return true;
    }
};