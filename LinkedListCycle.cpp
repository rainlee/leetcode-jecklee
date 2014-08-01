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