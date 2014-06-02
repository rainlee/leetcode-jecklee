/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * �ֱ������������mergeʱÿ��ȡС����һ����ʱ�临�Ӷ�O(m+n)
 * ע�⣺�Ƿ���Ҫ���ƽڵ�
 ***/
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (NULL == l1)
            return l2;
        if (NULL == l2)
            return l1;
            
        ListNode *phead = new ListNode(-1);  // null head
        ListNode *node = phead;
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        
        while (node1 && node2)
        {
            if (node1->val < node2->val)
            {
                node->next = node1;
                node1 = node1->next;
            }
            else
            {
                node->next = node2;
                node2 = node2->next;
            }
            node = node->next;
        }
        
        if (NULL == node1)  // the reset of l2
            node->next = node2;
        if (NULL == node2)
            node->next = node1;
        
        return phead->next;
    }
};