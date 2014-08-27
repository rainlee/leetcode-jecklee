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
 * ͬ������ָ�룬һ��������һ������
 * �����ظ��Ķ�Ҫɾ�������Ի���Ҫ������ָ�룬ָ��Ҫɾ������һ�ε�ǰһ���ڵ�
 * ���һ������������ֵͬ�Ľڵ㳬��������ȫ��ɾ��
 * ppre pstart ... pnode ...
 * ɾ��pstart��pnode��ͬ��һ��
 ***/
/*
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if ((NULL == head) || (NULL == head->next))
            return head;
        
        ListNode *phead = new ListNode(-1);  // null head node
        phead->next = head;
        
        ListNode *ppre = phead;  // before head
        ListNode *pstart = head;
        ListNode *pnode = head->next;  // next
        while (pnode)
        {
            if (pnode->val == pstart->val)
            {
                while (pnode && (pnode->val == pstart->val))
                    pnode = pnode->next;
                // remove duplicates
                ppre->next = pnode;
            }
            else
                ppre = pstart;
            
            // move on
            pstart = pnode;
            if (pnode)
                pnode = pnode->next;
        }
        
        return phead->next;
    }
};
*/

/***
 * ��2���ظ���ȫɾ������Ҫ��¼ǰ���ڵ�
 * ��next�ڵ�͵�ǰ���ȣ�������ƶ�
 * �����ҵ�������ȵĵ㣬ɾ����pre����
 * ��Ϊͷ�ڵ���ܱ�ɾ����������Ҫ��ͷ
 ***/
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !(head->next))
            return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *node = head;
        while (node && node->next)
        {
            if (node->next && node->next->val != node->val)
            {
                pre = node;
                node = node->next;
            }
            else
            {
                while (node->next && (node->val == node->next->val))
                    node = node->next;
                pre->next = node->next;
                node = node->next;
            }
        }
        return dummy.next;
    }
};