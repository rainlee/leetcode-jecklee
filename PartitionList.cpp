/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/***
 * ���ҵ���һ����С��x�ĵ�head2
 * �Ѹõ����С��x�ĵ���뵽head2֮ǰ
 ***/
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (NULL == head)
            return NULL;
        
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *slow = &dummy;
        while (slow->next && (slow->next->val < x))
            slow = slow->next;
    
        ListNode *prefast = slow;
        ListNode *fast = slow->next;
        while (fast)
        {
            if (fast->val < x)
            {
                prefast->next = fast->next;
                fast->next = slow->next;
                slow->next = fast;
                slow = slow->next;
                fast = prefast->next;  // prefast stays still
            }
            else
            {
                prefast = fast;
                fast = fast->next;
            }
        }
        return dummy.next;
    }
};