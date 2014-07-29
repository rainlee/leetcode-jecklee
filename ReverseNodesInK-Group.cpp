/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 分段处理
 * 往后数k个节点，然后将这一段逆置
 * 若不足k个，则返回
 ***/
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (NULL == head)
            return NULL;
            
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;   // pre of the segment
        ListNode *cur = head;
        ListNode *pstart = cur;
        ListNode *pend = NULL;
        int cnt = 0;
        while (cur)
        {
            if (++cnt == k)
            {
                pend = cur->next;
                pre->next = reverseList(pstart, pend);  // reverse cur seg, and connect to pre
                
                pre = pstart;   // pstart now is in the tail
                pstart = pend;  // pend is the head of next segment
                cnt = 0;
                cur = pend;     // cur->next != pend, cur is in the head now
            }
            else
                cur = cur->next;
        }
        return dummy.next;
    }
private:
    ListNode *reverseList(ListNode *pstart, ListNode *pend)
    {
        if ((NULL == pstart) || (pstart->next == pend))
            return pstart;
            
        ListNode *pre = NULL;
        ListNode *node = pstart;
        while (node != pend)
        {
            ListNode *pnext = node->next;
            node->next = pre;
            pre = node;
            node = pnext;
        }
        pstart->next = pend;  // connect the list with rest list
        return pre;
    }
};