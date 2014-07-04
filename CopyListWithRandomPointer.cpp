/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/***
 * ���α��� ʹ��nextָ��
 * ��һ�θ������е�next�ڵ㣬���ұ����¾ɽڵ��map
 * �ڶ�����map�в���random��Ӧ����ֵ��������randomָ��
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
 * ��2����1�е�map��Ϊ�˱����¾ɽڵ��ӳ���ϵ
 * ����ֱ����ԭ�����ÿ���ڵ����һ�� 1->2->3->NULL ==> 1->1->2->2->3->3->NULL
 * Ȼ������ڶ��飬����random�ڵ㣬��Ӧ�½ڵ��random��Ϊrandom->next
 * ��󣬽�����������
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