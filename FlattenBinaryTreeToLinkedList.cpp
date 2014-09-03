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
    void flatten(TreeNode *root) {
        TreeNode *last = NULL;
        preorderTravel(root, last);
    }
private:
    // caution, last node must be returned!!!
    void preorderTravel(TreeNode *root, TreeNode *&last)
    {
        if (NULL == root)
            return;
        TreeNode *rchild = root->right;  // right child will be replaced by lchild
        if (last)     // add cur node(root) to linked list
            last->right = root;
        last = root;
        
        preorderTravel(root->left, last);
        root->left = NULL;    // update left child
        preorderTravel(rchild, last);
        return;
    }
};

// ��һ����ͷ�����Բ����ж���һ���ڵ��Ƿ�Ϊ��
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode dummy(-1);
        TreeNode *last = &dummy;
        flattenRec(root, last);
    }
private:
    void flattenRec(TreeNode *root, TreeNode *&last)  // preorder
    {
        if (!root)
            return;
        TreeNode *rchild = root->right;
        last->right = root;
        last = root;
        flattenRec(root->left, last);
        root->left = NULL;   // break left subtree here!!!
        flattenRec(rchild, last);
    }
};