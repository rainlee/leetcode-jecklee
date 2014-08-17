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
 * ���ڵ� -> ���� -> �Һ���
 ***/
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        vtree.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return vtree;
    }
private:
    vector<int> vtree;
};
*/

/***
 * �ǵݹ�
 * ��һ��ջ�������·��
 * �ȷ��ʸ���㣬�������ջ���������ӣ�ֱ������Ϊ��
 * ��ջ�����ˣ������Һ���
 ***/
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (NULL == root)
            return vtree;
        
        stack<TreeNode *> stree;
        TreeNode *node = root;
        while (node || (!stree.empty()))
        {
            while (node)
            {
                vtree.push_back(node->val);   // visit cur node
                stree.push(node);             // push cur node
                node = node->left;
            }
            node = stree.top();  // pop the parent node
            stree.pop();
            node = node->right;  // visit the right child
        }
        return vtree;
    }
private:
    vector<int> vtree;
};
*/

/***
 * ��3��Morris, �ռ�O(1)
 * ����ͬ�������������ֻ���һ��
 * ��������ǵڶ��η���ʱ����������ǵ�һ�η���ʱ���
 * �������ߵ�����������������������������
 * �����Һ��ӵĴ�����һ���������������Һ���ָ�����ĺ�̸�
 ***/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vtree;
        if (!root)
            return vtree;
        TreeNode *node = root;
        while (node)
        {
            if (!(node->left))       // the leftest leaf node
            {
                vtree.push_back(node->val);
                node = node->right;
            }
            else
            {
                TreeNode *tmp = node->left;
                while (tmp->right && (tmp->right != node))  // the rightest node of lchild
                    tmp = tmp->right;
                if (!(tmp->right))               // first visit
                {
                    vtree.push_back(node->val);  // visit root(node) before move to node->left
                    tmp->right = node;           // connect to root
                    node = node->left;
                }
                else                             // second visit
                {
                    tmp->right = NULL;           // break the connection
                    node = node->right;
                }
            }
        }
        return vtree;
    }
};