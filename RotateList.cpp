/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 找到倒数第k个数，然后把后面k个数旋转到表头
 * 用快慢指针找到单链表倒数第个数
 * 快指针先走k步，然后快慢指针再同时走
 * 快指针到达尾部时，慢指针指在倒数第k个
 * note：k是否会超过表长
 ***/
/*
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
*/

/***
 * 法2：先遍历一遍，得出链表长度len，注意k可能大于len，因此令k%=len。
 * 将尾节点next指针指向首节点，形成一个环，接着往后跑len k步，从这里断开，就是要求的结果了。
 ***/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if ((NULL == head) || (0 == k))
            return head;
        
        int len = 1;
        ListNode *node = head;
        while (node->next)
        {
            ++len;
            node = node->next;
        }
        node->next = head;   // endless list
        
        int step = len - (k % len);
        while (step--)
            node = node->next;
        
        head = node->next;  // new head
        node->next = NULL;  // break the list
        return head;
    }
};