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
 * ����������Ľ�����һ��������Ϊ����
 * ����������ݹ�ʵ��
 * ���ڵ��������Һ�����ɣ�ԭ��������Ҫ�����Һ��ӣ�����Ҫ�����Һ���
 * �����������������ˣ�������Ҫ����������ת�����������next
 * ���Ե�֪�������������һ���ڵ㣨��һ������Ľڵ㣩
 ***/
class Solution {
public:
    void flatlr(TreeNode *root, TreeNode * &prenode)  // prenode, last node; caution, prenode must be returned!!!
    {
        if (NULL == root)
            return;
            
        prenode->right = root;   // add cur node(root) to linked list
        prenode = root;
        
        TreeNode *rchild = root->right; // right child will be replaced by lchild
        
        flatlr(root->left, prenode);
        root->left = NULL;            // update left child
        
        flatlr(rchild, prenode);
    }
    
    void flatten(TreeNode *root) {
        if (NULL == root)
            return;
        
        TreeNode *prenode = new TreeNode(-1);  // fake prenode
        flatlr(root, prenode);
        
        return;
    }
};