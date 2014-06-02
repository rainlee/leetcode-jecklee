/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * ����ָ���ҵ�������n���ڵ�
 * ע�⣺1. n > lenl ���������ɾ��
 *       2. n = lenl �������ɾ��ͷ���
 *       3. �Ƿ���Ҫ�ͷŽڵ�ռ�
 ***/
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if ((NULL == head) || (0 == n))
            return head;
        
        ListNode *pfast = head;
        ListNode *pslow = head;
        while (pfast && n--)
            pfast = pfast->next;
            
        if ((n > 0) && (NULL == pfast))  // n > lenl
            return head;
        if ((n == 0) && (NULL == pfast)) // n = lenl
            return head->next;
        
        while (pfast->next)   // pslow stops at (n+1)th
        {
            pslow = pslow->next;
            pfast = pfast->next;
        }
        
        pslow->next = pslow->next->next; // remove pslow->next
        
        return head;
    }
};