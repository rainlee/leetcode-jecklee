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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/***
 * 快慢双指针
 * p指针遍历，q指针复制
 * 不等则复制，相等则跳过
 ***/
/*
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if ((NULL == head) || (NULL == head->next))
            return head;
        
        ListNode *p = head->next;
        ListNode *q = head;
        while (p)
        {
            if (p->val != q->val)
            {
                q->next = p;
                q = q->next;  // move
            }
            p = p->next;     // else continue
        }
        q->next = NULL;   // caution: terminal
        
        return head;
    }
};
*/

/***
 * 法2：记录当前节点，往后遍历到第一个不等于当前节点的点
 * 删除中间的相等节点
 * 由于第一个节点一定不会被删除，故不用添加空头
 ***/
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !(head->next))
            return head;
        
        ListNode *node = head;
        while (node)
        {
            ListNode *cur = node;
            while (node && (node->val == cur->val))
                node = node->next;
            cur->next = node;
        }
        return head;
    }
};