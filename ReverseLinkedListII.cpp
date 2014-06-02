/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 计数 + 就地逆置
 * 先找到m点，然后m-n逆置，最后把前中三段拼起来
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