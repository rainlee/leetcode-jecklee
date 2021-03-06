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
 * 求出以每个节点为终点的最大路径（节点值 + 左/右子树）
 * 最大路径为 穿越该节点的左右子树最大路径相加
 ***/
/*
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        maxp = INT_MIN;
        maxSum(root);
        
        return maxp;
    }
private:
    int maxSum(TreeNode *root)
    {
        if (NULL == root)
            return 0;
        
        int pathsum = root->val;
        
        int maxl = maxSum(root->left);
        if (maxl > 0)           // root + left child tree
            pathsum += maxl;
            
        
        int maxr = maxSum(root->right);
        if (maxr > 0)           // root + right child tree
            pathsum += maxr;
        
        if (pathsum > maxp)   // max {root->val, root->val + maxl, root->val + maxr, root->val + maxl + maxr}
            maxp = pathsum;
        
        // max {root->val, root->val + maxl, root->val + maxr}
        int maxlr = max(maxl, maxr);
        return max(root->val, root->val + maxlr);
    }
    
    
    int maxp;
};
*/

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        maxp = INT_MIN;
        maxSumlr(root);
        return maxp;
    }
private:
    int maxp;
    // return, max path end with root
    int maxSumlr(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxl = maxSumlr(root->left);
        int maxr = maxSumlr(root->right);
        
        int pathsum = root->val + ((maxl > 0) ? maxl : 0) + ((maxr > 0) ? maxr : 0);  // path including root
        maxp = max(maxp, pathsum);
        
        return max(max(maxl, maxr) + root->val, root->val);  // path end with root
    }
};