/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * ʹ�ÿ���ָ���ж��Ƿ��л�
 * ���л���������������
 * ���ͷ������ڵľ���Ϊa������ָ��������λ�õ���ھ���Ϊb������Ϊl
 * �� 2 * (a + b) = a + k*l + b
 * a = k*l + b
 * ��ʹ�õڶ������ָ�룬һ���ӱ�ͷ��������һ���ӻ�������λ�ó�����һ����һ��
 * ���ջ�����ڴ�����
 ***/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if ((NULL == head) || (NULL == head->next))
            return NULL;
        
        ListNode *pslow = head;
        ListNode *pfast = head;
        while (pfast && pfast->next)
        {
            pslow = pslow->next;
            pfast = pfast->next->next;
            if (pslow == pfast)
                break;
        }
        if ((NULL == pfast) || (NULL == pfast->next))
            return NULL;
            
        ListNode *pslow2 = head;
        ListNode *pfast2 = pfast;   // �����ĵط�
        while (1)
        {
            if (pslow2 == pfast2)
                break;
            pslow2 = pslow2->next;
            pfast2 = pfast2->next;
        }
        
        return pslow2;
    }
};