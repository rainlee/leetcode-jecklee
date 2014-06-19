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
 * 中序遍历
 * 记录路径 和 路径和
 * 进入递归时 push 当前节点，返回时pop 还原现场
 ***/
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vvpaths.clear();
        vpath.clear();
        
        getPath(root, sum);
        
        return vvpaths;
    }
private:
    void getPath(TreeNode *root, int sum)
    {
        if (NULL == root)
            return;
        
        vpath.push_back(root->val);
        sum -= root->val;
        
        if ((NULL == root->left) && (NULL == root->right))  // leaf node
        {
            if (0 == sum)
                vvpaths.push_back(vpath);
            
            vpath.pop_back();  // pop cur node
            return;
        }
        
        getPath(root->left, sum);
        getPath(root->right, sum);
        
        vpath.pop_back();      // pop cur node
        return;
    }

    vector<vector<int> > vvpaths;
    vector<int> vpath;
};