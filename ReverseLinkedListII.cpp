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
 * ���� + �͵�����
 * ���ҵ�m�㣬Ȼ��m-n���ã�����ǰ������ƴ����
 * ��m-nǰ�嵽tail1�ĺ��棬ע���м���β�Ҫ�ͺ���Ͽ���
 ***/
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if ((NULL == head) || (NULL == head->next) || (m == n))
            return head;
        
        ListNode *phead = new ListNode(-1); // null head
        phead->next = head;
        
        ListNode *pre = phead;
        ListNode *cur = head;
        
        int cnt = 1;
        while (cur && (cnt != m))
        {
            pre = cur;
            cur = cur->next;
            ++cnt;
        }
        ListNode *tail1 = pre;
        
        while (cur && (cnt < n))
        {
            pre = cur;
            cur = cur->next;
            ++cnt;
            
            pre->next = cur->next;    // insert cur after tail1
            cur->next = tail1->next;
            tail1->next = cur;
            
            cur = pre;  // set cur
        }
        
        return phead->next;
    }
};

/*
// �����������׳���
// ���ַ�����ֻ��ǰ�壬�м����ǰ�����ˣ�����head2����ʱ������β���ͺ���������
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || !(head->next))
            return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *node = &dummy;
        int cnt = 1;
        while (node && (cnt < m))
        {
            ++cnt;
            node = node->next;
        }
        ListNode *tail = node;  // tail of first part
        ListNode *head2 = node->next;
        node = head2->next;
        while (node && (cnt < n))
        {
            ++cnt;
            ListNode *tailnext = tail->next;
            ListNode *nodenext = node->next;
            
            tail->next = node;
            node->next = tailnext;
            
            node = nodenext;
        }
        head2->next = node;
        return dummy.next;
    }
};
*/