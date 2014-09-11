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
        if (!root)
            return vtree;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        vtree.push_back(root->val);
        return vtree;
    }
private:
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
/*
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
*/

/***
 * ��3��Morris ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
 * �����������Ը��ӣ���Ҫ����һ����ʱ�ڵ�dummy������������root��
 * ���һ���Ҫһ���ӹ��̣����ǵ������ĳ�����ڵ�֮��·���ϵĸ����ڵ㡣
 * ͬ����һֱ�����ߣ��������ӣ���������
 * ��һ�η��������������Һ���ʱ���������ӵ�root�ϣ���̣�
 * �ڶ��η���ʱ����������ӵ�ǰ�ڵ�����ӵ���ǰ���ڵ�����·���ϵ����нڵ㡣
 * ���ҶϿ�ǰ���ڵ��root
 * ע�⵹�������Ҫ����ת����Ȼ�������֮������ת����
 ***/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        
        TreeNode dummy(-1);
        dummy.left = root;
        TreeNode *node = &dummy;
        while (node)
        {
            if (!(node->left))
                node = node->right;
            else
            {
                TreeNode *tmp = node->left;
                while (tmp->right && (tmp->right != node))
                    tmp = tmp->right;
                if (!(tmp->right))      // first visit
                {
                    tmp->right = node;  // connect
                    node = node->left;
                }
                else
                {
                    reverseVisitNodes(node->left, tmp);
                    tmp->right = NULL;  // break
                    node = node->right;
                }
            }
        }
        return vtree;
    }
private:
    vector<int> vtree;
    
    void reverseTreeList(TreeNode *start, TreeNode *end)
    {
        if (start == end)
            return;
        TreeNode *pre = start;
        TreeNode *cur = start->right;
        while (true)
        {
            TreeNode *next = cur->right;
            cur->right = pre;
            if (cur == end)
                break;
            pre = cur;
            cur = next;
        }
    }
    // visit nodes from end to start
    void reverseVisitNodes(TreeNode *start, TreeNode *end)
    {
        if (!start)
            return;
        reverseTreeList(start, end);
        TreeNode *node = end;
        while (true)
        {
            vtree.push_back(node->val);
            if (node == start)
                break;
            node = node->right;
        }
        reverseTreeList(end, start);   // reduce
    }
};

/**********************************************************/
// ������� ���Ҹ�
// ������� �����󣬹۲췢�֣�ǡ����ǰ������ĶԳ���ʽ
// ���Կ���������ǰ������ķ����������������Ȼ������
/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        reversePreorderTree(root);
        reverse(vtree.begin(), vtree.end());
        return vtree;
    }
private:
    vector<int> vtree;
    void reversePreorderTree(TreeNode *root)
    {
        if (!root)
            return;
        
        vtree.push_back(root->val);
        reversePreorderTree(root->right);
        reversePreorderTree(root->left);
        return;
    }
};
*/

/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        reversePreorderTree(root);
        reverse(vtree.begin(), vtree.end());
        return vtree;
    }
private:
    vector<int> vtree;
    
    void reversePreorderTree(TreeNode *root)
    {
        if (!root)
            return;
        
        stack<TreeNode *> stree;
        TreeNode *node = root;
        while (node || !stree.empty())
        {
            while (node)
            {
                vtree.push_back(node->val);
                stree.push(node);
                node = node->right;
            }
            node = stree.top();
            stree.pop();
            node = node->left;
        }
        return;
    }
};
*/

// morris
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        reversePreorderTree(root);
        reverse(vtree.begin(), vtree.end());
        return vtree;
    }
private:
    vector<int> vtree;
    
    void reversePreorderTree(TreeNode *root)
    {
        if (!root)
            return;
        
        TreeNode *node = root;
        while (node)
        {
            if (!node->right)
            {
                vtree.push_back(node->val);
                node = node->left;
            }
            else
            {
                TreeNode *tmp = node->right;
                while ((NULL != tmp->left) && (node != tmp->left))
                    tmp = tmp->left;
                if (!tmp->left)
                {
                    vtree.push_back(node->val);
                    tmp->left = node;
                    node = node->right;
                }
                else
                {
                    tmp->left = NULL;
                    node = node->left;
                }
            }
        }
    }
};