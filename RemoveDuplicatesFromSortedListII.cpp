/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 同样两个指针，一个遍历，一个复制
 * 由于重复的都要删掉，所以还需要第三个指针，指向要删除的这一段的前一个节点
 * 外加一个计数器，相同值的节点超过两个则全部删除
 * ppre pstart ... pnode ...
 * 删除pstart到pnode相同的一段
 ***/
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if ((NULL == head) || (NULL == head->next))
            return head;
        
        ListNode *phead = new ListNode(-1);  // null head node
        phead->next = head;
        
        ListNode *ppre = phead;  // before head
        ListNode *pstart = head;
        ListNode *pnode = head->next;  // next
        while (pnode)
        {
            if (pnode->val == pstart->val)
            {
                while (pnode && (pnode->val == pstart->val))
                    pnode = pnode->next;
                // remove duplicates
                ppre->next = pnode;
            }
            else
                ppre = pstart;
            
            // move on
            pstart = pnode;
            if (pnode)
                pnode = pnode->next;
        }
        
        return phead->next;
    }
};