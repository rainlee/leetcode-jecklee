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
 * 法1：递归
 * 后序遍历，左孩子 -> 右孩子 -> 根节点
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
 * 法2：非递归
 * 用一个栈保存遍历路径
 * 根结点入栈，找到最左孩子，路径所有结点入栈
 * 访问最左孩子，访问右子树（右孩子入栈）
 * 有两个时刻需要出栈，当左右孩子为空时 & 当左右孩子都已访问时
 * 故每次出栈时，标记上一个已访问的结点
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