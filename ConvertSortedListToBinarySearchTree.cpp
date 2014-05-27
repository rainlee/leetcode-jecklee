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