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
 * ���� -> ���ڵ� -> �Һ���
 ***/
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (NULL == root)
            return vtree;
        return inTree(root);
    }
private:
    vector<int> &inTree(TreeNode *root)
    {
        if (NULL == root)
            return vtree;
        
        inTree(root->left);
        vtree.push_back(root->val);
        inTree(root->right);
        
        return vtree;
    }
    
    vector<int> vtree;
};
*/

/***
 * �ǵݹ�
 * ��ջ�������·��
 * ������ջ��һֱ��������
 * ��ջ�������Һ���
 ***/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (NULL == root)
            return vtree;
            
        stack<TreeNode *> stree;
        TreeNode *node = root;
        
        while (node || (!stree.empty()))
        {
            while (node)
            {
                stree.push(node);
                node = node->left;
            }
            if (!stree.empty())
            {
                node = stree.top();
                stree.pop();
                
                vtree.push_back(node->val);  // visit cur node
                
                node = node->right;          // visit right child, may be null
            }
        }
        return vtree;
    }
private:
    vector<int> vtree;
};