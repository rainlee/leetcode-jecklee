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
 * �����������������������
 * �������ʱ��¼ǰһ���ڵ㣬�����򣨵�ǰ���ֵ < ǰһ���ڵ�ֵ��ʱ����Ҫ����˳��
 * �������ʱֻ����һ������㣬˵������������ڵ����ڣ����������������
 ***/
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if (NULL == root)
            return;
            
        prenode = NULL;
        pm1 = NULL;
        pm2 = NULL;
        
        inorderTree(root);
        swap(pm1->val, pm2->val);
        
        return;
    }
private:
    void inorderTree(TreeNode *root)
    {
        if (NULL == root)
            return;
        
        inorderTree(root->left);
        
        if ((NULL != prenode) && (root->val < prenode->val))
        {
            if (NULL == pm1)    // ��һ������
            {
                pm1 = prenode;  // prenodeһ���������
                pm2 = root;     // ��ǰ��root�����ǣ����ڣ���Ҳ���ܲ���
            }
            else
                pm2 = root;     // �ڶ�������
        }
        prenode = root;   // set prenode
        
        inorderTree(root->right);
    }

    TreeNode *prenode;
    TreeNode *pm1;     // mistake
    TreeNode *pm2;
};