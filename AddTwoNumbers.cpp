/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * ���������������ʾһ�����ģ�ͷ�ڵ�ָ���λ
 * ��ǰ������ע���λ
 ***/
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        ListNode dummy(-1);
        ListNode *node = &dummy;
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        int c = 0;
        while (node1 || node2 || c)
        {
            int d = c;
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
            c = d / 10;
            d %= 10;
            node->next = new ListNode(d);
            node = node->next;
        }
        return dummy.next;
    }
};