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
 * 二叉查找树中序遍历是升序的
 * 中序遍历时记录前一个节点，当乱序（当前结点值 < 前一个节点值）时，需要调整顺序
 * 如果遍历时只出现一个乱序点，说明乱序的两个节点相邻；否则有两个乱序点
 ***/
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if (NULL == root)
            return;
            
        prenode = NULL;
        pm1 = NULL;
        pm2 = NULL;
        
        inorderTree(root);
        swap(pm1->val, pm2->val);
        
        return;
    }
private:
    void inorderTree(TreeNode *root)
    {
        if (NULL == root)
            return;
        
        inorderTree(root->left);
        
        if ((NULL != prenode) && (root->val < prenode->val))
        {
            if (NULL == pm1)    // 第一次乱序
            {
                pm1 = prenode;  // prenode一定是乱序点
                pm2 = root;     // 当前点root可能是（相邻），也可能不是
            }
            else
                pm2 = root;     // 第二次乱序
        }
        prenode = root;   // set prenode
        
        inorderTree(root->right);
    }

    TreeNode *prenode;
    TreeNode *pm1;     // mistake
    TreeNode *pm2;
};