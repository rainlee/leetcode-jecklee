/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 找到倒数第k个数，然后把后面k个数旋转到表头
 * 用快慢指针找到单链表倒数第个数
 * 快指针先走k步，然后快慢指针再同时走
 * 快指针到达尾部时，慢指针指在倒数第k个
 * note：k是否会超过表长
 ***/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if ((NULL == head) || (0 == k))
            return head;
        
        ListNode *pfast = head;
        ListNode *pslow = head;
        int cnt = k;   // find the reverse kth
        while (cnt--)   // what to do if k > lenl
        {
            pfast = pfast->next;
            if (NULL == pfast)    // k > lenl
                pfast = head;
        }
        
        while (pfast->next)  // pfast stops at the last node, pslow at (k-1)th
        {
            pslow = pslow->next;
            pfast = pfast->next;
        }
        
        pfast->next = head;
        head = pslow->next;  // rotate list
        pslow->next = NULL;
        
        return head;
    }
};