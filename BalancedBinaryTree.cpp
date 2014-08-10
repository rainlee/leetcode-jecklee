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
 * 法1：递归求树深，然后比较左右子树
 * 并递归分别判断左右子树
 * 缺点：会重复求树深
 ***/
/*
class Solution {
public:
    int treeDepth(TreeNode *root)
    {
        if (NULL == root)
            return 0;
        
        return max(treeDepth(root->left), treeDepth(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode *root) {
        if (NULL == root)
            return true;
        
        int depl = treeDepth(root->left);
        int depr = treeDepth(root->right);
        int diff = abs(depl - depr);
        if (diff > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
*/

/***
 * 法2：一边遍历求树深，一边判断是否平衡
 ***/
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int h;
        return isBalRec(root, h);
    }
private:
    bool isBalRec(TreeNode *root, int &height)
    {
        if (!root)
        {
            height = 0;
            return true;
        }
        int lh = 0;
        int rh = 0;
        if (!isBalRec(root->left, lh) || !isBalRec(root->right, rh))
            return false;
        height = max(lh, rh) + 1;
        return (abs(lh - rh) <= 1);
    }
};