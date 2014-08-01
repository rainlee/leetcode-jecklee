/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 快慢指针
 * 慢指针一次走一步，快指针一次走两步
 * 如果慢指针能追上快指针，则有环
 ***/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ((NULL == head) || (NULL == head->next))
            return false;
        
        ListNode *pslow = head;
        ListNode *pfast = head;
        
        while (pfast && pfast->next)
        {
            pslow = pslow->next;
            pfast = pfast->next->next;
            
            if (pslow == pfast)
                return true;
        }
        return false;
    }
};