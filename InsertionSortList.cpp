/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/***
 * 插入排序
 * 每次从前往后找一个合适的位置插入
 * 已经遍历的部分是有序的
 ***/
/*
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if ((NULL == head) || (NULL == head->next))
            return head;
            
        ListNode *phead = new ListNode(INT_MIN);  // fake head node
        phead->next = head;
        
        ListNode *pnode = head;
        ListNode *nnode = head->next;
        while (nnode)
        {
            // find a position from [phead, nnode] to insert nnode
            ListNode *pnode2 = phead;            // phead here, not head
            ListNode *nnode2 = phead->next;
            while ((nnode2 != nnode) && (nnode2->val <= nnode->val))
            {
                pnode2 = nnode2;
                nnode2 = nnode2->next;
            }
            
            if (nnode2 == nnode) // dont need to insert
            {
                pnode = nnode;
                nnode = nnode->next;
            }
            else
            {
                pnode->next = nnode->next;  // delete nnode
                
                pnode2->next = nnode;   // insert nnode
                nnode->next = nnode2;
                
                nnode = pnode->next;   // get next node
            }
        }
        //pnode->next = NULL;   // caution
        
        return phead->next;
    }
};
*/

// 和法1是一样的，练练手……
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        // foreach from head to tail to find the insertion place
        if (!head || !(head->next))
            return head;
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode *pre = head;
        ListNode *node = head->next;
        while (node)
        {
            ListNode *next = node->next;
            ListNode *node2 = &dummy;  // foreach from head
            while ((node2 != node) && (node2->next->val <= node->val))
                node2 = node2->next;
            if (node2 == node)
                pre = node;     //  node stays still
            else
            {
                node->next = node2->next;
                node2->next = node;
                pre->next = next;  // pre stays still
            }
            node = next;    // move on
        }
        return dummy.next;
    }
};