/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/***
 * 后半部分逆置
 * 前后两部分归并
 ***/
class Solution {
public:
    void reorderList(ListNode *head) {
        if ((NULL == head) || (NULL == head->next) || (NULL == head->next->next))
            return;
        
        int len = 0;
        ListNode *pnode = head;
        while (pnode)
        {
            len++;
            pnode = pnode->next;
        }
        
        ListNode *headl = head;
        ListNode *headr = NULL;
        pnode = head;
        int mid = (len+1) / 2;   // lenl >= lenr
        while (--mid)
            pnode = pnode->next;
        headr = pnode->next;
        pnode->next = NULL;      // break list
        
        // reverse right part list
        headr = reverseList(headr);
        
        mergeList(headl, headr);
    }
private:
    ListNode *reverseList(ListNode *head)
    {
        if ((NULL == head) || (NULL == head->next))
            return head;
        
        ListNode *phead = new ListNode(-1);
        phead->next = head;
        
        ListNode *pnode = phead;
        ListNode *nnode = head;
        while (nnode)
        {
            ListNode *ptmp = nnode->next;
            nnode->next = pnode;
            pnode = nnode;
            nnode = ptmp;
        }
        head->next = NULL;
        
        return pnode;
    }
    
    void mergeList(ListNode *headl, ListNode *headr)
    {
        if ((NULL == headl) || (NULL == headr))
            return;
            
        ListNode *pnodel = headl;
        ListNode *pnoder = headr;
        while (pnodel && pnoder)
        {
            ListNode *ptmpl = pnodel->next;
            ListNode *ptmpr = pnoder->next;
            
            pnodel->next = pnoder;
            pnoder->next = ptmpl;
            
            pnodel = ptmpl;
            pnoder = ptmpr;
        }
    }
};