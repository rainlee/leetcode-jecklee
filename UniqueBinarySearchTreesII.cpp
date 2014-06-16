/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> gTrees(int low, int high)
    {
        vector <TreeNode *> vtree;
        if (low > high)
        {
            vtree.push_back(NULL);  // note: 加入空结点!
            return vtree;
        }
        
        for (int i = low; i <= high; i++)  // 以i为根结点
        {
            vector<TreeNode *> vleft = gTrees(low, i-1);    // 构建左右子树
            vector<TreeNode *> vright = gTrees(i+1, high);
            
            // 左右子树进行组合
            for (int j = 0; j < vleft.size(); j++)
            {
                for (int k = 0; k < vright.size(); k++)
                {
                    // 生成根结点，左右子树分别取一种情况组合
                    TreeNode *root = new TreeNode(i);  // val = i
                    root->left = vleft[j];
                    root->right = vright[k];
                    vtree.push_back(root);
                }
            }
        }
        
        return vtree;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        return gTrees(1, n);
    } 
};