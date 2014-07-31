/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/***
 * �ݹ�
 * ���ҵ�������е㣬��Ϊ��
 * Ȼ��ֱ�������������
 * ���е㣬�����ÿ���ָ�룬һ����һ����һ��������
 ***/
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (NULL == head)
            return NULL;
        
        // find mid of list
        ListNode *prenode = NULL;  // be used when break the list
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            prenode = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // new a TreeNode, and process the children recursivly
        TreeNode *root = new TreeNode(slow->val);
        if (prenode)
        {
            prenode->next = NULL;    // break the list
            root->left = sortedListToBST(head);
        }
        else
            root->left = NULL;
            
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};