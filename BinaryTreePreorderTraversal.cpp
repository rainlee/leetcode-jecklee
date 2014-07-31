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
 * 根节点 -> 左孩子 -> 右孩子
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
 * 非递归
 * 用一个栈保存遍历路径
 * 先访问根结点，根结点入栈，访问左孩子，直到左孩子为空
 * 出栈，回退，访问右孩子
 ***/
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