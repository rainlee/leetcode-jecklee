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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

        // 两个指针，一个先走n步，此时另外一个从头走
        // 第一个指针到末尾是，第二个指针在倒数第n+1个
        if ((NULL == head) || (0 == n))
            return head;

        ListNode *fast = head;
        ListNode *slow = head;

        while ((NULL != fast) && n--)  // fast 走n步
            fast = fast->next;

        if ((n > 0) && (NULL == fast))   // 链表长度小于n
            return head;
        else if ((n == 0) && (NULL == fast))
            return head->next;           // 长度刚好为n，删除第一个

        while (NULL != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // 删除slow后面的结点
        slow->next = slow->next->next;

        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    Solution so;

    ListNode *head2 = so.removeNthFromEnd(head, 1);

    if (head2 == NULL)
        cout << "empty list!" << endl;
    else
        cout << "the first node: " << head->val << endl;
    return 0;
}
