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
 * 同 按层遍历
 * 用队列记录遍历路径
 * 奇数层从右往左（先右孩子入队，后左孩子入队）（level从1开始）
 * 偶数层从左往右（先左后右）
 * 以上用队列的方法是错的…奇数层是乱序的……
 * 应该用栈
 * 奇数层从左往右，偶数层从右往左
 * 用两个栈，分别记录奇数层和偶数层……
 ***/
/*
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if (NULL == root)
            return vvtree;
        
        stack<TreeNode *> stree_odd;
        stack<TreeNode *> stree_even;
        stree_odd.push(root);
        
        int level = 1;
        int n1 = 1;
        int n2 = 0;
        TreeNode *node;
        vector<int> vlevel;
        
        while (!stree_odd.empty() || !stree_even.empty())
        {
            if (level & 0x01)
            {
                node = stree_odd.top();
                stree_odd.pop();                 // pop from stree_odd
                vlevel.push_back(node->val);
                
                if (node->left)
                {
                    stree_even.push(node->left); // push into stree_even
                    ++n2;
                }
                if (node->right)
                {
                    stree_even.push(node->right);
                    ++n2;
                }
            }
            else
            {
                node = stree_even.top();
                stree_even.pop();                 // pop from stree_even
                vlevel.push_back(node->val);
                
                if (node->right)
                {
                    stree_odd.push(node->right);  // push into stree_odd
                    ++n2;
                }
                if (node->left)
                {
                    stree_odd.push(node->left);
                    ++n2;
                }
            }
            
            if (0 == --n1)
            {
                vvtree.push_back(vlevel);
                vlevel.clear();
                
                n1 = n2;
                n2 = 0;
                ++level;
            }
        }
        return vvtree;
    }
private:
    vector<vector<int> > vvtree;
};
*/

/***
 * 法2：不用这么麻烦……
 * 直接按层顺序遍历，然后偶数行的结果逆序
 ***/
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
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
                vvtree.push_back(vlevel);
                vlevel.clear();
                
                n1 = n2;
                n2 = 0;
            }
        }
        
        // reverse odd level
        for (int i = 1; i < vvtree.size(); i += 2)
            for (int j = 0; j < vvtree[i].size()/2; ++j)
                swap(vvtree[i][j], vvtree[i][vvtree[i].size() - j - 1]);
        
        return vvtree;
    }
private:
    vector<vector<int> > vvtree;
};