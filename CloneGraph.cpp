/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

/***
 * 先复制当前节点，然后依次复制邻居
 * 使用DFS遍历图
 * 为避免重复制，用一个map记录已经复制的节点
 ***/
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