/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/***
 * 链表二分归并
 * 等分链表，先排左边，再排右边
 * 然后左右两边归并
 ***/
class Solution {
public:
    ListNode *mergeL(ListNode *list1, ListNode *list2)
    {
        if (NULL == list1)
            return list2;
        if (NULL == list2)
            return list1;
        
        ListNode *pnode1 = list1;
        ListNode *pnode2 = list2;
        ListNode *phead = new ListNode(-1);  // null head list node
        ListNode *pnode = phead;
        
        while (pnode1 || pnode2)
        {
            if (NULL == pnode1)
            {
                pnode->next = pnode2;
                break;
            }
            else if (NULL == pnode2)
            {
                pnode->next = pnode1;
                break;
            }
            else if (pnode1->val < pnode2->val)
            {
                pnode->next = pnode1;
                pnode = pnode->next;
                pnode1 = pnode1->next;
            }
            else
            {
                pnode->next = pnode2;
                pnode = pnode->next;
                pnode2 = pnode2->next;
            }
        }
        
        return phead->next;
    }
    ListNode *binSortL(ListNode *head, int len)
    {
        if ((NULL == head) || (NULL == head->next))
            return head;
        
        ListNode *headr = head;
        ListNode *headl = NULL;
        
        ListNode *pnode = head;
        int len2 = len / 2 - 1;
        while (len2--)
            pnode = pnode->next;
        
        headl = pnode->next;
        pnode->next = NULL;
        
        headr = binSortL(headr, len/2);
        headl = binSortL(headl, len - len/2);
        
        return mergeL(headr, headl);
    }
    ListNode *sortList(ListNode *head) {
        if ((NULL == head) || (NULL == head->next))
            return head;
        
        int n = 0;
        ListNode *pnode = head;
        while (pnode)
        {
            n++;
            pnode = pnode->next;
        }
        return binSortL(head, n);
    }
};