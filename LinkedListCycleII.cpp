/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 使用快慢指针判断是否有环
 * 若有环，满足以下条件
 * 设表头到环入口的距离为a，快慢指针相遇的位置到入口距离为b，环长为l
 * 则 2 * (a + b) = a + k*l + b
 * a = k*l + b
 * 再使用第二组快慢指针，一个从表头触发，另一个从环上相遇位置出发，一次走一步
 * 最终会在入口处相遇
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
        ListNode *pfast2 = pfast;   // 相遇的地方
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