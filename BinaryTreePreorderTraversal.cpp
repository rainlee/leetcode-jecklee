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
 * 法1：递归 
 * 根节点 -> 左孩子 -> 右孩子
 ***/
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        vtree.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return vtree;
    }
private:
    vector<int> vtree;
};
*/

/***
 * 非递归
 * 用一个栈保存遍历路径
 * 先访问根结点，根结点入栈，访问左孩子，直到左孩子为空
 * 出栈，回退，访问右孩子
 ***/
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (NULL == root)
            return vtree;
        
        stack<TreeNode *> stree;
        TreeNode *node = root;
        while (node || (!stree.empty()))
        {
            while (node)
            {
                vtree.push_back(node->val);   // visit cur node
                stree.push(node);             // push cur node
                node = node->left;
            }
            node = stree.top();  // pop the parent node
            stree.pop();
            node = node->right;  // visit the right child
        }
        return vtree;
    }
private:
    vector<int> vtree;
};
*/

/***
 * 非递归算法：同样是使用栈，先访问当前节点
 * 接着右孩子入栈、左孩子入栈
 * 然后处理左子树，即出栈，栈为空退出
 ***/
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vtree;
        if(!root) 
            return vtree;
        stack<TreeNode *> s;
        TreeNode *node = root;
        while(node)
        {
            vtree.push_back(node->val);
            if(node->right) 
                s.push(node->right);
            if(node->left) 
                s.push(node->left);
            
            if(s.empty()) 
                break;
            else
            {
                node = s.top();
                s.pop();
            }
        }
        return vtree;
    }
};
*/

/***
 * 法3：Morris, 空间O(1)
 * 方法同中序遍历，代码只相差一行
 * 中序遍历是第二次访问时输出，先序是第一次访问时输出
 * 不是先走到最左孩子输出，而是先输出再往左走
 * 另外右孩子的处理方法一样，左子树的最右孩子指向他的后继根
 ***/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vtree;
        if (!root)
            return vtree;
        TreeNode *node = root;
        while (node)
        {
            if (!(node->left))       // the leftest leaf node
            {
                vtree.push_back(node->val);
                node = node->right;
            }
            else
            {
                TreeNode *tmp = node->left;
                while (tmp->right && (tmp->right != node))  // the rightest node of lchild
                    tmp = tmp->right;
                if (!(tmp->right))               // first visit
                {
                    vtree.push_back(node->val);  // visit root(node) before move to node->left
                    tmp->right = node;           // connect to root
                    node = node->left;
                }
                else                             // second visit
                {
                    tmp->right = NULL;           // break the connection
                    node = node->right;
                }
            }
        }
        return vtree;
    }
};