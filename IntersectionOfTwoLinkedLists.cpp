/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         God Bless Me     BUG Free Forever
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 法1：
 * 1 分别求出两个链表的长度lenA lenB
 * 2 短的先走|lenA - lenB|
 * 3 然后两个链表一起往后走，直到相遇或者某条链走完
 ***/
/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        if (lenA > lenB)
        {
            int dif = lenA - lenB;
            while (dif--)
                node1 = node1->next;
        }
        else if (lenA < lenB)
        {
            int dif = lenB - lenA;
            while (dif--)
                node2 = node2->next;
        }
        while (node1 && node2)
        {
            if (node1 == node2)
                return node1;
            node1 = node1->next;
            node2 = node2->next;
        }
        return NULL;
    }
private:
    int getListLength(ListNode *head)
    {
        ListNode *node = head;
        int len = 0;
        while (node)
        {
            ++len;
            node = node->next;
        }
        return len;
    }
};
*/

/***
 * 法2：
 * 1 将链表B连接到A的后面
 * 2 在链表A中找环，若有环，则环的入口则为两链表交点
 * 3 断开两链表
 ***/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int lenA = connectList(headA, headB);
        ListNode *node = findCycleEnt(headA);
        breakList(headA, lenA);  // ERROR: linked structure was modified.
        return node;
    }
private:
    int connectList(ListNode *headA, ListNode *headB) 
    {
        if (!headA || !headB) return 0;
        ListNode *node = headA;
        int lenA = 1;
        while (node->next)
        {
            ++lenA;
            node = node->next;
        }
        node->next = headB;
        return lenA;
    }
    ListNode *findCycleEnt(ListNode *head)
    {
        if (!head) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (slow != fast) return NULL;
        
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    void breakList(ListNode *head, int len)
    {
        if (!head) return;
        ListNode *node = head;
        while (--len)
            node = node->next;
        node->next = NULL;
        return;
    }
};