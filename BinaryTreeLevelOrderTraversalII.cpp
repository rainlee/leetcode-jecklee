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
 * 按层遍历，从底往输出
 * 还是从上往下遍历，用队列记录路径，同Binary Tree Level Order Traversal
 * 每一层的遍历结果往前插就行了
 * 注：vector insert 耗时152ms，而先push_back，最后再调整顺序，只需要20ms!?
 ***/
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        if (NULL == root)
            return vvtree;
            
        queue<TreeNode *> qtree;
        qtree.push(root);
        
        int n1 = 1;
        int n2 = 0;
        vector<int> vlevel;
        
        TreeNode *node;
        while (!qtree.empty())
        {
            node = qtree.front();
            qtree.pop();
            vlevel.push_back(node->val);
            
            if (node->left)
            {
                qtree.push(node->left);
                ++n2;
            }
            if (node->right)
            {
                qtree.push(node->right);
                ++n2;
            }
            
            if (0 == --n1)  // end of cur level
            {
                //vvtree.insert(vvtree.begin(), vlevel);  // insert into the head
                vvtree.push_back(vlevel);
                vlevel.clear();
                
                n1 = n2;
                n2 = 0;
            }
        }
        
        // reverse the vector
        int level = vvtree.size() / 2;
        for (int i = 0; i < level; ++i)
            vvtree[i].swap(vvtree[vvtree.size() - i - 1]);
        
        return vvtree;
    }
private:
    vector<vector<int> > vvtree;
};