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
 * 法1：递归，每次取左右子树小的一个
 * 从底向上
 ***/
/*
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (NULL == root)
            return 0;
        
        int minl = minDepth(root->left);
        int minr = minDepth(root->right);
        
        if (minl && minr)
            return min(minl, minr) + 1;
        else
            return minl + minr + 1;  // (0 == minl) || (0 == minr)
    }
};
*/

/***
 * 法2：递归 + 剪枝
 * DFS 记录当前的mindep
 * 从根向叶子遍历，超过mindep则break
 ***/
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (NULL == root)
            return 0;
        
        mindep = INT_MAX;
        minDep(root, 0);
        
        return mindep;
    }
private:
    int mindep;
    
    void minDep(TreeNode *root, int dep)
    {
        if (NULL == root)
            return;
        
        if (++dep >= mindep)
            return;
        
        if ((NULL == root->left) && (NULL == root->right))
        {
            if (dep < mindep)
            {
                mindep = dep;
                return;
            }
        }
        
        minDep(root->left, dep);
        minDep(root->right, dep);
        
        return;
    }
};