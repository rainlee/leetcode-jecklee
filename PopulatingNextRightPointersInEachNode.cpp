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
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/***
 * 法1：按层遍历
 * 将每一层连接成单链表
 * 时间复杂度O(n) 空间复杂度 O(n)
 ***/
/*
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (NULL == root)
            return;
        
        queue<TreeLinkNode *> qtree;
        TreeLinkNode *node = root;
        TreeLinkNode *pre = NULL;
        int n = 1;
        int cnt = 0;
        qtree.push(root);    // first push root
        while (!qtree.empty())
        {
            // travel in level order
            node = qtree.front();
            qtree.pop();
            
            if (node->left)
                qtree.push(node->left);
            if (node->right)
                qtree.push(node->right);
            
            // connect link list
            if (pre)
                pre->next = node;
                
            if (++cnt == n)  // end of this level
            {
                pre = NULL;
                n *= 2;
                cnt = 0;
            }
            else
                pre = node;
        }
        return;
    }
};
*/

/***
 * 法2：递归 先序遍历
 * 由于是完全二叉树，则同一个根节点的左孩子next一定指向右孩子
 * 右孩子的next指向root的兄弟的左孩子
 * 时间复杂度O(n) 空间复杂度O(logn)
 ***/
/*
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root || !root->left)
            return;
            
        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : NULL; // silbling of root
        
        connect(root->left);
        connect(root->right);
        return;
    }
};
*/

/***
 * 法3：迭代 按层遍历
 * 同样利用完全二叉树的特点，用一个指针last记录上一个结点
 ***/
/*
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *node = root;
        while (node)
        {
            TreeLinkNode *level = node;
            TreeLinkNode *last = NULL;
            while (level && level->left)
            {
                if (last)
                    last->next = level->left;      // connect last node to cur node
                level->left->next = level->right;  // connect two siblings
                last = level->right;               // update last node
                level = level->next;               // next node in this level
            }
            node = node->left;  // next level
        }
        return;
    }
};
*/

/***
 * 同样 迭代 按层遍历
 * 同样利用完全二叉树的特点，不需要last指针
 * 每次处理level的左右孩子，左孩子指向右孩子，右孩子指向level->next的左孩子
 ***/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *node = root;
        while (node)
        {
            TreeLinkNode *level = node;
            while (level)
            {
                if (level->left)
                    level->left->next = level->right;
                if (level->right && level->next)
                    level->right->next = level->next->left;
                level = level->next;
            }
            node = node->left;
        }
        return;
    }
};