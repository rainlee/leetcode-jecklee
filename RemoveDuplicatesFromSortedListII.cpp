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
 * 同样两个指针，一个遍历，一个复制
 * 由于重复的都要删掉，所以还需要第三个指针，指向要删除的这一段的前一个节点
 * 外加一个计数器，相同值的节点超过两个则全部删除
 * ppre pstart ... pnode ...
 * 删除pstart到pnode相同的一段
 ***/
/*
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if ((NULL == head) || (NULL == head->next))
            return head;
        
        ListNode *phead = new ListNode(-1);  // null head node
        phead->next = head;
        
        ListNode *ppre = phead;  // before head
        ListNode *pstart = head;
        ListNode *pnode = head->next;  // next
        while (pnode)
        {
            if (pnode->val == pstart->val)
            {
                while (pnode && (pnode->val == pstart->val))
                    pnode = pnode->next;
                // remove duplicates
                ppre->next = pnode;
            }
            else
                ppre = pstart;
            
            // move on
            pstart = pnode;
            if (pnode)
                pnode = pnode->next;
        }
        
        return phead->next;
    }
};
*/

/***
 * 法2：重复的全删除，需要记录前驱节点
 * 若next节点和当前不等，则向后移动
 * 否则找到所有相等的点，删除，pre不动
 * 因为头节点可能被删除，所以需要空头
 ***/
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !(head->next))
            return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *node = head;
        while (node && node->next)
        {
            if (node->next && node->next->val != node->val)
            {
                pre = node;
                node = node->next;
            }
            else
            {
                while (node->next && (node->val == node->next->val))
                    node = node->next;
                pre->next = node->next;
                node = node->next;
            }
        }
        return dummy.next;
    }
};