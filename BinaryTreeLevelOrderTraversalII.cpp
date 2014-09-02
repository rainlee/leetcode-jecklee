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
 * ����������ӵ������
 * ���Ǵ������±������ö��м�¼·����ͬBinary Tree Level Order Traversal
 * ÿһ��ı��������ǰ�������
 * ע��vector insert ��ʱ152ms������push_back������ٵ���˳��ֻ��Ҫ20ms!?
 ***/
/*
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
*/

/***
 * ��2����NULL��ʶһ�еĽ�β
 ***/
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > vtree;
        if (!root)
            return vtree;
        
        queue<TreeNode *> qtree;
        qtree.push(root);
        qtree.push(NULL);
        vector<int> vlevel;
        while (true)
        {
            TreeNode *node = qtree.front();
            qtree.pop();
            if (!node)  // end of level
            {
                vtree.push_back(vlevel);
                vlevel.clear();
                if (qtree.empty())
                    break;
                qtree.push(NULL);
            }
            else
            {
                vlevel.push_back(node->val);
                if (node->left)
                    qtree.push(node->left);
                if (node->right)
                    qtree.push(node->right);
            }
        }
        // reverse vector
        //for (int i = 0; i < vtree.size()/2; ++i)
        //    vtree[i].swap(vtree[vtree.size() - i - 1]);
        reverse(vtree.begin(), vtree.end());
        return vtree;
    }
};