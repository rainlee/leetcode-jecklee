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
 * ��1���ݹ�
 * ������������� -> �Һ��� -> ���ڵ�
 ***/
/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (NULL == root)
            return vtree;
        
        return postTree(root);
    }
private:
    vector<int> &postTree(TreeNode *root)
    {
        if (NULL == root)
            return vtree;
        postTree(root->left);
        postTree(root->right);
        vtree.push_back(root->val);
        
        return vtree;
    }
    
    vector<int> vtree;
};
*/

/***
 * ��2���ǵݹ�
 * ��һ��ջ�������·��
 * �������ջ���ҵ������ӣ�·�����н����ջ
 * ���������ӣ��������������Һ�����ջ��
 * ������ʱ����Ҫ��ջ�������Һ���Ϊ��ʱ & �����Һ��Ӷ��ѷ���ʱ
 * ��ÿ�γ�ջʱ�������һ���ѷ��ʵĽ��
 ***/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (NULL == root)
            return vtree;
        
        stack<TreeNode *> stree;
        TreeNode *node = root;
        TreeNode *prenode = NULL;
        
        while (node || (!stree.empty()))
        {
            while (node)
            {
                stree.push(node);
                node = node->left;
            }
            
            node = stree.top();
            
            if ((NULL == node->right) || (prenode == node->right))
            {
                vtree.push_back(node->val);   // visit cur node
                prenode = node;               // mark the pre node
                stree.pop();
                node = NULL;                  // cur node has been visited
            }
            else
                node = node->right;
        }
        return vtree;
    }
private:
    vector<int> vtree;
};