/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 从前往后处理，每次处理一对
 * 为方便处理，添加一个头节点
 ***/
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *node = head;
        while (node && node->next)
        {
            ListNode *next1 = node->next;
            ListNode *next2 = node->next->next;
            pre->next = next1;
            next1->next = node;
            node->next = next2;
            pre = node;        // update prenode
            node = next2;      // move on
        }
        return dummy.next;
    }
};