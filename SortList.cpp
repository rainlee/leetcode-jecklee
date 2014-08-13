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
/*
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
*/

/***
 * 法2：使用快慢指针找中点，然后断开前后两部分
 * 先排前面 再排后面 然后merge
 ***/
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !(head->next))
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;
        
        ListNode *headl = sortList(head);
        ListNode *headr = sortList(head2);
        return mergeList(headl, headr);
    }
private:
    ListNode *mergeList(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(-1);
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        ListNode *node = &dummy;
        while (node1 && node2)
        {
            if (node1->val <= node2->val)
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
        if (!node1)
            node->next = node2;
        if (!node2)
            node->next = node1;
        return dummy.next;
    }
};