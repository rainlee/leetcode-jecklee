/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/***
 * 两次遍历 使用next指针
 * 第一次复制所有的next节点，并且保存新旧节点的map
 * 第二次在map中查找random对应的新值，并更新random指针
 ***/
/*
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (NULL == head)
            return NULL;
        
        RandomListNode *pnode1 = head;
        
        RandomListNode *phead2 = new RandomListNode(-1);
        RandomListNode *pnode2 = phead2;
        
        map<RandomListNode *, RandomListNode *> rrmap;
        
        // step 1: copy next
        while (pnode1)
        {
            RandomListNode *ptmp = new RandomListNode(pnode1->label);
            pnode2->next = ptmp;
            pnode2 = ptmp;
            
            rrmap.insert(map<RandomListNode *, RandomListNode *>::value_type(pnode1, pnode2));
            
            pnode1 = pnode1->next;
        }
        
        // step 2: copy random
        pnode1 = head;
        pnode2 = phead2->next;
        while (pnode1)
        {
            map<RandomListNode *, RandomListNode *>::iterator it = rrmap.find(pnode1->random); // random map node1 -> node2
            if (it != rrmap.end())
                pnode2->random = it->second;
            
            pnode1 = pnode1->next;
            pnode2 = pnode2->next;
        }
        
        return phead2->next;
    }
};
*/

/***
 * 法2：法1中的map是为了保存新旧节点的映射关系
 * 可以直接在原链表的每个节点后复制一份 1->2->3->NULL ==> 1->1->2->2->3->3->NULL
 * 然后遍历第二遍，复制random节点，对应新节点的random即为random->next
 * 最后，将链表拆成两个
 ***/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (NULL == head)
            return NULL;
        
        RandomListNode *node = head;   // copy node
        while (node)
        {
            RandomListNode *newnode = new RandomListNode(node->label);
            newnode->next = node->next;
            node->next = newnode;
            
            node = newnode->next;
        }
        
        node = head;   // copy random node
        while (node)
        {
            if (node->random != NULL)   // caution: maybe NULL
                node->next->random = node->random->next;
            node = node->next->next;
        }
        
        node = head;
        RandomListNode *prehead2 = new RandomListNode(-1);  // partition
        RandomListNode *node2 = prehead2;
        while (node)
        {
            node2->next = node->next;
            node2 = node->next;
            
            node->next = node->next->next;
            node = node->next;
        }
        
        return prehead2->next;
    }
};