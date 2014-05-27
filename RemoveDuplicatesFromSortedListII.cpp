/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * ͬ������ָ�룬һ��������һ������
 * �����ظ��Ķ�Ҫɾ�������Ի���Ҫ������ָ�룬ָ��Ҫɾ������һ�ε�ǰһ���ڵ�
 * ���һ������������ֵͬ�Ľڵ㳬��������ȫ��ɾ��
 * ppre pstart ... pnode ...
 * ɾ��pstart��pnode��ͬ��һ��
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