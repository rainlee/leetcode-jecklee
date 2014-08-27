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
 * ���������ͳһ������Populating Next Right Pointers in Each Node
 * ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(n)
 ***/
/*
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (NULL == root)
            return;
        
        queue<TreeLinkNode *> qtree;
        qtree.push(root);
        TreeLinkNode *node = root;
        TreeLinkNode *pre = NULL;
        int n1 = 1;
        int n2 = 0;
        int cnt = 0;
        while (!qtree.empty())
        {
            node = qtree.front();
            qtree.pop();
            
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
            
            if (pre)
                pre->next = node;
            
            if (++cnt == n1) // end of this level
            {
                pre = NULL;
                n1 = n2;
                n2 = 0;
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
 * ��2���ݹ�
 * һ��һ�㴦����Ǹò��һ���ڵ�first��ǰһ��������Ľڵ�last
 * �ȴ������ӣ������Һ��ӣ�Ȼ�����ڵ��next
 * ������һ��(root->next == NULL)���ݹ鴦��first
 * ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(logn)
 ***/
/*
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (NULL == root)
            return;
        
        TreeLinkNode dummy(-1);  // first node
        TreeLinkNode *node = root;
        TreeLinkNode *pre = &dummy;
        while (node)
        {
            if (node->left)
            {
                pre->next = node->left;
                pre = pre->next;
            }
            if (node->right)
            {
                pre->next = node->right;
                pre = pre->next;
            }
            node = node->next;   // next node in this level
        }
        connect(dummy.next);     // next level
    }
};
*/

/***
 * ��3����2��β�ݹ�ĵ���
 * ����ѭ�������ѭ�������У��ڲ�ѭ������ÿ�е�LinkList
 * ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
 ***/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *node = root;
        while (node)
        {
            TreeLinkNode dummy(-1);   // head of this level
            TreeLinkNode *level = node;
            TreeLinkNode *pre = &dummy;
            while (level)
            {
                if (level->left)
                {
                    pre->next = level->left;
                    pre = pre->next;
                }
                if (level->right)
                {
                    pre->next = level->right;
                    pre = pre->next;
                }
                level = level->next;   // next node in this level
            }
            node = dummy.next;   // next level
        }
    }
};