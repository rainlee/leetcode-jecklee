#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reList(ListNode *start, ListNode *end)  // end ָ��β����next
    {
        ListNode *pre = start;
        ListNode *node = start->next;
        ListNode *next = node;

        while (node != end)
        {
            next = node->next;
            node->next = pre;

            pre = node;
            node = next;
        }
        start->next = end;  // ����ͷ���
        return pre;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {

       // ��������
       // ��һ�����Ƿ�ʣ�»���k�����
       // ����У�����еڶ��α�������������
       // ���û�У��򷵻�

       ListNode *next = head;
       ListNode *start = head;
       ListNode *end = NULL;
       ListNode *newhead = new ListNode(-1);  // Ϊ����ͷ��㴦��
       newhead->next = head;

       ListNode *pre = newhead;   // ָ��ͷ���֮ǰ
       int cnt = 0;
       while (next)
       {
           if (++cnt == k)
           {
               end = next->next;
               pre->next = reList(start, end);

               pre = start;   // ���ú�ǰһ�ε����һ�����
               cnt = 0;       // ע�⻹ԭ�м����
               start = end;
               next = end;    // ע�����ʱ��next�Ѿ����ã������˸öεĶ���
           }
           else
               next = next->next;
       }
       return newhead->next;
    }
};

int main()
{
    Solution so;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode *newhead = so.reverseKGroup(head, 2);

    ListNode *pnode = newhead;
    while (pnode)
    {
        cout << pnode->val << " ";
        pnode = pnode->next;
    }

    return 0;

}
