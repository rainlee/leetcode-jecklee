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
 * ��1���ݹ飬ÿ��ȡ��������С��һ��
 * �ӵ�����
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
 * ��2���ݹ� + ��֦
 * DFS ��¼��ǰ��mindep
 * �Ӹ���Ҷ�ӱ���������mindep��break
 * �Զ�����
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
            mindep = min(mindep, dep);
            return;
        }
        
        minDep(root->left, dep);
        minDep(root->right, dep);
        
        return;
    }
};