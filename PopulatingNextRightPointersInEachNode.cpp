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
 * ��1���������
 * ��ÿһ�����ӳɵ�����
 * ʱ�临�Ӷ�O(n) �ռ临�Ӷ� O(n)
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
 * ��2���ݹ� �������
 * ��������ȫ����������ͬһ�����ڵ������nextһ��ָ���Һ���
 * �Һ��ӵ�nextָ��root���ֵܵ�����
 * ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(logn)
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
 * ��3������ �������
 * ͬ��������ȫ���������ص㣬��һ��ָ��last��¼��һ�����
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
 * ͬ�� ���� �������
 * ͬ��������ȫ���������ص㣬����Ҫlastָ��
 * ÿ�δ���level�����Һ��ӣ�����ָ���Һ��ӣ��Һ���ָ��level->next������
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