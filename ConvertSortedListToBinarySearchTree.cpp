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
 * 递归
 * 先找到链表的中点，设为根
 * 然后分别处理左右两部分
 * 找中点，可以用快慢指针，一个走一步，一个走两步
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