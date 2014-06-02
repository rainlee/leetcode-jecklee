/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 维护一个长度为k的小顶堆
 * 每次从各个有序表中取一个放入堆中
 * 然后从中取最小的加入到新的链表
 * 小顶堆可以用priority_queue
 ***/
struct cmpnode {
    bool operator() (ListNode *a, ListNode *b)
    {
        return (a->val > b->val);
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (0 == lists.size())
            return NULL;
        
        priority_queue<ListNode *, vector<ListNode *>, cmpnode> pheap;
        for (int i = 0; i < lists.size(); ++i)
            if (NULL != lists[i])
                pheap.push(lists[i]);
        
        ListNode *mlist = new ListNode(-1);  // null head
        ListNode *mnode = mlist;
        
        while (!pheap.empty())
        {
            ListNode *pnode = pheap.top();  // get the smallest node
            pheap.pop();
            
            mnode->next = pnode;  // merge
            mnode = pnode;
            
            if (NULL != pnode->next)
                pheap.push(pnode->next);
        }
        
        return mlist->next;
    }
};