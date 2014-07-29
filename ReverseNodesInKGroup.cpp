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
    ListNode *reList(ListNode *start, ListNode *end)  // end 指向尾结点的next
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
        start->next = end;  // 处理头结点
        return pre;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {

       // 遍历两遍
       // 第一遍检查是否剩下还有k个结点
       // 如果有，则进行第二次遍历，逆置链表
       // 如果没有，则返回

       ListNode *next = head;
       ListNode *start = head;
       ListNode *end = NULL;
       ListNode *newhead = new ListNode(-1);  // 为方便头结点处理
       newhead->next = head;

       ListNode *pre = newhead;   // 指向头结点之前
       int cnt = 0;
       while (next)
       {
           if (++cnt == k)
           {
               end = next->next;
               pre->next = reList(start, end);

               pre = start;   // 逆置后，前一段的最后一个结点
               cnt = 0;       // 注意还原中间变量
               start = end;
               next = end;    // 注意这个时候next已经逆置，放在了该段的段首
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
