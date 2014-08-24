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
 * 计数 + 就地逆置
 * 先找到m点，然后m-n逆置，最后把前中三段拼起来
 * 把m-n前插到tail1的后面，注意中间这段不要和后面断开了
 ***/
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if ((NULL == head) || (NULL == head->next) || (m == n))
            return head;
        
        ListNode *phead = new ListNode(-1); // null head
        phead->next = head;
        
        ListNode *pre = phead;
        ListNode *cur = head;
        
        int cnt = 1;
        while (cur && (cnt != m))
        {
            pre = cur;
            cur = cur->next;
            ++cnt;
        }
        ListNode *tail1 = pre;
        
        while (cur && (cnt < n))
        {
            pre = cur;
            cur = cur->next;
            ++cnt;
            
            pre->next = cur->next;    // insert cur after tail1
            cur->next = tail1->next;
            tail1->next = cur;
            
            cur = pre;  // set cur
        }
        
        return phead->next;
    }
};

/*
// 链表的题很容易出错
// 这种方法是只管前插，中间这段前插完了，再用head2（这时候在链尾）和后面连起来
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || !(head->next))
            return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *node = &dummy;
        int cnt = 1;
        while (node && (cnt < m))
        {
            ++cnt;
            node = node->next;
        }
        ListNode *tail = node;  // tail of first part
        ListNode *head2 = node->next;
        node = head2->next;
        while (node && (cnt < n))
        {
            ++cnt;
            ListNode *tailnext = tail->next;
            ListNode *nodenext = node->next;
            
            tail->next = node;
            node->next = tailnext;
            
            node = nodenext;
        }
        head2->next = node;
        return dummy.next;
    }
};
*/