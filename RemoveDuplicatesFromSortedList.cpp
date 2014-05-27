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