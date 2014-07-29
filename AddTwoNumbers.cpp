/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 由于链表是逆序表示一个数的，头节点指向个位
 * 从前往后处理，注意进位
 ***/
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2 )
            return NULL;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        ListNode dummy(-1);
        ListNode *node = &dummy;
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        int c = 0;
        while (node1 || node2)
        {
            int d = 0;
            if (node1)
            {
                d += node1->val;
                node1 = node1->next;
            }
            if (node2)
            {
                d += node2->val;
                node2 = node2->next;
            }
            d += c;
            c = d / 10;
            d = d % 10;
            ListNode *tmp = new ListNode(d);
            node->next = tmp;
            node = node->next;
        }
        if (c)
        {
            ListNode *tmp = new ListNode(c);
            node->next = tmp;
        }
        return dummy.next;
    }
};