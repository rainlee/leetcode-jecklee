/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/***
 * 先找到第一个不小于x的点head2
 * 把该点后面小于x的点插入到head2之前
 ***/
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (NULL == head)
            return NULL;
        
        ListNode *phead = new ListNode(-1);
        phead->next = head;
        ListNode *pre = phead;
        ListNode *cur = head;
        
        while (cur && (cur->val < x))
        {
            pre = cur;
            cur = cur->next;
        }
        
        ListNode *tail1 = pre;  // find the head2
        ListNode *head2 = cur;
        
        while (cur)
        {
            if (cur->val < x)
            {
                pre->next = cur->next;
                
                tail1->next = cur;
                cur->next = head2;
                
                tail1 = cur;
                cur = pre->next;  // pre and head2 not changed
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        
        return phead->next;
    }
};