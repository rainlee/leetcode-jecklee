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
 * 二叉树按层遍历
 * 用一个队列记录遍历路径
 * 先访问根节点，然后左孩子入队 右孩子入队
 * 同时，用变量记录每一层的节点数 和 下一层的子结点数
 ***/
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        if (NULL == root)
            return vvtree;
        
        queue<TreeNode *> qtree;
        qtree.push(root);
        
        int n1 = 1;  // cur level
        int n2 = 0;  // next level
        vector<int> vlevel;
        TreeNode *node;
        
        while (!qtree.empty())
        {
            node = qtree.front();
            qtree.pop();
            
            vlevel.push_back(node->val);  // visit cur node
            
            if (node->left)
            {
                qtree.push(node->left);
                n2++;
            }
            if (node->right)
            {
                qtree.push(node->right);
                n2++;
            }
            
            if (0 == --n1)  // end of cur level, move to next level
            {
                vvtree.push_back(vlevel);   // save cur level
                vlevel.clear();             // prepare for next level
                
                n1 = n2;
                n2 = 0;
            }
        }
        
        return vvtree;
    }
private:
    vector<vector<int> > vvtree;
};