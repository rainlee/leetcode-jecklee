/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 快慢指针找到倒数第n个节点
 * 注意：1. n > lenl 的情况，不删除
 *       2. n = lenl 的情况，删除头结点
 *       3. 是否需要释放节点空间
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