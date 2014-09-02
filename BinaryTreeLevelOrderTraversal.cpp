/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         God Bless Me     BUG Free Forever
*/
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
/*
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
*/

/***
 * 法2：为了分割各层，加入NULL作为一层的结尾
 ***/
/*
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > vtree;
        if (!root)
            return vtree;
        
        queue<TreeNode *> qtree;
        qtree.push(root);
        qtree.push(NULL);      // as terminal
        vector<int> vlevel;
        while (true)
        {
            TreeNode *node = qtree.front();
            qtree.pop();
            if (!node)   // NULL
            {
                vtree.push_back(vlevel);
                vlevel.clear();
                if (qtree.empty())  // end
                    break;
                qtree.push(NULL);   // end of level
            }
            else
            {
                vlevel.push_back(node->val);  // save cur node
                if (node->left)
                    qtree.push(node->left);
                if (node->right)
                    qtree.push(node->right);
            }
        }
        return vtree;
    }
};
*/

/***
 * 法3：DFS 递归
 * 中序遍历，注意初始化每层的vtree
 ***/
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        levelOrderRec(root, 0);
        return vtree;
    }
private:
    vector<vector<int> > vtree;
    void levelOrderRec(TreeNode *node, int level)
    {
        if (!node)
            return;
        if (vtree.size() <= level)
            vtree.push_back(vector<int>());  // init
        vtree[level].push_back(node->val);
        levelOrderRec(node->left, level+1);
        levelOrderRec(node->right, level+1);
    }
};