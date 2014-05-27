/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * ����ָ��
 * ��ָ��һ����һ������ָ��һ��������
 * �����ָ����׷�Ͽ�ָ�룬���л�
 ***/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ((NULL == head) || (NULL == head->next))
            return false;
        
        ListNode *plow = head;
        ListNode *pfast = head;
        
        while (pfast && pfast->next)
        {
            plow = plow->next;
            pfast = pfast->next->next;
            
            if (plow == pfast)
                return true;
        }
        return false;
    }
};