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
 * ����˫ָ��
 * pָ�������qָ�븴��
 * �������ƣ����������
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
 * ��2����¼��ǰ�ڵ㣬�����������һ�������ڵ�ǰ�ڵ�ĵ�
 * ɾ���м����Ƚڵ�
 * ���ڵ�һ���ڵ�һ�����ᱻɾ�����ʲ�����ӿ�ͷ
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