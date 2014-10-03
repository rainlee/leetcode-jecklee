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
 * 扩展：如果是非连通图，则图定义如下
 * struct Graph {
 *     vector<GraphNode *> nodes;
 * };
 * 需要对每个nodes[i]调用cloneGraph()
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
// 假如label可以重复，则需要记录原节点指针
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
            (clonenode->neighbors).push_back(cloneGraph((node->neighbors)[i]));

        return clonenode;
    }
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mgraph;
};
*/

/***
 * 法2：BFS遍历图
 * 先node入队，然后邻居依次入队
 * 为避免重复复制，用一个map记录已经分配的节点
 * 注意：复制node 和 neighbors之前，都需要查重
 * 入队时复制点，出队时复制边
 ***/
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mgraph;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        mgraph[node] = new UndirectedGraphNode(node->label);
        while (!q.empty())
        {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            UndirectedGraphNode *newcur = mgraph[cur];
            if (!newcur->neighbors.empty())
                continue;
            
            for (int i = 0; i < cur->neighbors.size(); ++i)
            {
                UndirectedGraphNode *newngh = NULL;
                if (mgraph.find(cur->neighbors[i]) != mgraph.end())
                    newngh = mgraph[cur->neighbors[i]];
                else
                {
                    newngh = new UndirectedGraphNode(cur->neighbors[i]->label);
                    mgraph[cur->neighbors[i]] = newngh;
                }
                newcur->neighbors.push_back(newngh);
                q.push(cur->neighbors[i]);
            }
        }
        return mgraph[node];
    }
};