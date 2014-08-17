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
        if (!root)
            return vtree;
        inorderTraversal(root->left);
        vtree.push_back(root->val);
        inorderTraversal(root->right);
        return vtree;
    }
private:
    vector<int> vtree;
};
*/

/***
 * �ǵݹ�
 * ��ջ�������·��
 * ������ջ��һֱ��������
 * ��ջ�������Һ���
 ***/
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vtree;
        if (!root)
            return vtree;
            
        stack<TreeNode *> stree;
        TreeNode *node = root;
        while (node || !stree.empty())
        {
            while (node)
            {
                stree.push(node);
                node = node->left;      // visit left
            }
            node = stree.top();
            stree.pop();
            vtree.push_back(node->val); // visit root
            node = node->right;         // visit right, may be null
        }
        return vtree;
    }
};
*/

/***
 * ��3��O(1)�ռ��������Morris�㷨
 * Ҫʹ��O(1)�ռ���б����������ѵ����ڣ��������ӽڵ��ʱ���������·��ص����ڵ�
 *������ڵ���û��ָ�򸸽ڵ��pָ�룩
 * Morris����ʹ��������������threaded binary tree����
 * ��Morris�����в���ҪΪÿ���ڵ�������ָ��ָ����ǰ���ͺ�̽ڵ㣬ֻ��Ҫ����Ҷ�ӽڵ�
 * �е����ҿ�ָ��ָ��ĳ��˳������µ�ǰ���ڵ���̽ڵ�Ϳ����ˡ�
 * ��������Ҷ�ӽ�����ָ�룬ָ�����̽�㣬���һ�������ڵڶ��α�����������ʱ��
 * �������������Ѿ��������ˣ�����ʸý��
 * Ҳ���ǣ���һ�η���rootʱ��������������(root->left)�����ҽڵ�ָ���(root)
 * �������������ҽڵ�(node->right)����root��˵���ǵڶ��η���root
 * ��������Ĺ��򣬴�ʱӦ�����root
 * ע�⣺��ԭ�����������ҽڵ�node->right = NULL
 ***/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vtree;
        if (!root)
            return vtree;
        
        TreeNode *node = root;
        while (node)
        {
            if (!(node->left))  // the leftest leaf node
            {
                vtree.push_back(node->val);
                node = node->right;
            }
            else
            {
                TreeNode *tmp = node->left;
                while (tmp->right && (node != tmp->right))  // find the rightest node of lchild
                    tmp = tmp->right;
                if (!(tmp->right))      // first visit
                {
                    tmp->right = node;  // connect rightest node to root
                    node = node->left;  // continue, back to root->left
                }
                else                    // second visit
                {
                    vtree.push_back(node->val);
                    tmp->right = NULL;  // caution: break the connection between rightest node and root
                    node = node->right;
                }
            }
        }
        return vtree;
    }
};