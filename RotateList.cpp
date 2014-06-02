/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * �ҵ�������k������Ȼ��Ѻ���k������ת����ͷ
 * �ÿ���ָ���ҵ����������ڸ���
 * ��ָ������k����Ȼ�����ָ����ͬʱ��
 * ��ָ�뵽��β��ʱ����ָ��ָ�ڵ�����k��
 * note��k�Ƿ�ᳬ����
 ***/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if ((NULL == head) || (0 == k))
            return head;
        
        ListNode *pfast = head;
        ListNode *pslow = head;
        int cnt = k;   // find the reverse kth
        while (cnt--)   // what to do if k > lenl
        {
            pfast = pfast->next;
            if (NULL == pfast)    // k > lenl
                pfast = head;
        }
        
        while (pfast->next)  // pfast stops at the last node, pslow at (k-1)th
        {
            pslow = pslow->next;
            pfast = pfast->next;
        }
        
        pfast->next = head;
        head = pslow->next;  // rotate list
        pslow->next = NULL;
        
        return head;
    }
};