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
 * 递归
 * 左孩子 -> 根节点 -> 右孩子
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
 * 非递归
 * 用栈保存遍历路径
 * 左孩子入栈，一直到最左孩子
 * 出栈，访问右孩子
 ***/
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