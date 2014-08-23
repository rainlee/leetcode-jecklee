/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

/***
 * �ȸ��Ƶ�ǰ�ڵ㣬Ȼ�����θ����ھ�
 * ʹ��DFS����ͼ
 * Ϊ�����ظ��ƣ���һ��map��¼�Ѿ����ƵĽڵ�
 ***/
/*
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (NULL == node)
            return NULL;
        
        mgraph.clear();
        return dfs(node);
    }
    
private:
    UndirectedGraphNode *dfs(UndirectedGraphNode *node)
    {
        if (NULL == node)
            return NULL;
            
        if (mgraph.find(node->label) != mgraph.end())  // has been cloned
            return mgraph[node->label];
        
        UndirectedGraphNode *clonenode = new UndirectedGraphNode(node->label);
        mgraph[node->label] = clonenode;    // save in map
        
        // clone the neighbors
        UndirectedGraphNode *clonengh = NULL;
        for (int i = 0; i < (node->neighbors).size(); ++i)
        {
            clonengh = dfs((node->neighbors)[i]);  // clone the ith neighbor
            (clonenode->neighbors).push_back(clonengh);
        }
        
        return clonenode;
    }
    map<int, UndirectedGraphNode *> mgraph;  // (label, graph) unique label
};
*/

/*
// ����label�����ظ�������Ҫ��¼ԭ�ڵ�ָ��
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (NULL == node)
            return NULL;
        if (mgraph.find(node) != mgraph.end())
            return mgraph[node];
        UndirectedGraphNode *clonenode = new UndirectedGraphNode(node->label);
        mgraph[node] = clonenode;
        for (int i = 0; i < (node->neighbors).size(); ++i)
        {
            UndirectedGraphNode *ngh = cloneGraph((node->neighbors)[i]);
            (clonenode->neighbors).push_back(ngh);
        }
        return clonenode;
    }
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mgraph;
};
*/

/***
 * ��2��BFS����ͼ
 * ��node��ӣ�Ȼ���ھ��������
 * Ϊ�����ظ����ƣ���һ��map��¼�Ѿ�����Ľڵ�
 * ע�⣺����node �� neighbors֮ǰ������Ҫ����
 ***/
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (NULL == node)
            return NULL;
        
        unordered_map<int, UndirectedGraphNode *> mgraph;  // (label, node)
        queue<UndirectedGraphNode *> qgraph;               // queue for BFS
        qgraph.push(node);
        
        while (!qgraph.empty())
        {
            UndirectedGraphNode *curnode = qgraph.front();
            qgraph.pop();
            
            // clone cur node
            UndirectedGraphNode *clonenode = NULL;
            if (mgraph.find(curnode->label) != mgraph.end())
                clonenode = mgraph[curnode->label];
            else
            {
                clonenode = new UndirectedGraphNode(curnode->label);
                mgraph[curnode->label] = clonenode;
            }
            
            // clone neighbors
            vector<UndirectedGraphNode *> &nghs = curnode->neighbors;
            if (!(clonenode->neighbors).empty())  // has been cloned
                continue;
            for (int i = 0; i < nghs.size(); ++i)
            {
                qgraph.push(nghs[i]);    // push the ith ngh
                
                UndirectedGraphNode *ngh = NULL;
                if (mgraph.find(nghs[i]->label) != mgraph.end())
                    ngh = mgraph[nghs[i]->label];
                else
                {
                    ngh = new UndirectedGraphNode(nghs[i]->label);
                    mgraph[ngh->label] = ngh;
                }
                (clonenode->neighbors).push_back(ngh);
            }
        } // end of while
        return mgraph[node->label];
    }
};