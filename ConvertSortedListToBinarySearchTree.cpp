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
    TreeNode *SL2BST(ListNode *head)
    {
        if (NULL == head)
            return NULL;
        
        // find mid of list
        ListNode *prenode = NULL;  // be used when break the list
        ListNode *pslow = head;
        ListNode *pfast = head;
        
        while (pfast && pfast->next)
        {
            prenode = pslow;
            pslow = pslow->next;
            pfast = pfast->next->next;
        }
        
        // new a TreeNode
        TreeNode *root = new TreeNode(pslow->val);
        
        if (prenode)
        {
            prenode->next = NULL;  // break the list
            root->left = SL2BST(head);
        }
        else
            root->left = NULL;
        
        root->right = SL2BST(pslow->next);  // right part
        
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if (NULL == head)
            return NULL;
        
        return SL2BST(head);
    }
};