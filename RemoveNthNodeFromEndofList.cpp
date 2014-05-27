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

        // ����ָ�룬һ������n������ʱ����һ����ͷ��
        // ��һ��ָ�뵽ĩβ�ǣ��ڶ���ָ���ڵ�����n+1��
        if ((NULL == head) || (0 == n))
            return head;

        ListNode *fast = head;
        ListNode *slow = head;

        while ((NULL != fast) && n--)  // fast ��n��
            fast = fast->next;

        if ((n > 0) && (NULL == fast))   // ������С��n
            return head;
        else if ((n == 0) && (NULL == fast))
            return head->next;           // ���ȸպ�Ϊn��ɾ����һ��

        while (NULL != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // ɾ��slow����Ľ��
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
