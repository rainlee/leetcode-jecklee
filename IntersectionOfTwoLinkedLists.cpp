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
 * ��1��
 * 1 �ֱ������������ĳ���lenA lenB
 * 2 �̵�����|lenA - lenB|
 * 3 Ȼ����������һ�������ߣ�ֱ����������ĳ��������
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
 * ��2��
 * 1 ������B���ӵ�A�ĺ���
 * 2 ������A���һ������л����򻷵������Ϊ��������
 * 3 �Ͽ�������
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