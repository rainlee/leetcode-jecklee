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
 * �ȸ��Ƶ�ǰ�ڵ㣬Ȼ�����θ����ھ�
 * ʹ��DFS����ͼ
 * Ϊ�����ظ��ƣ���һ��map��¼�Ѿ����ƵĽڵ�
 * ��չ������Ƿ���ͨͼ����ͼ��������
 * struct Graph {
 *     vector<GraphNode *> nodes;
 * };
 * ��Ҫ��ÿ��nodes[i]����cloneGraph()
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
            (clonenode->neighbors).push_back(cloneGraph((node->neighbors)[i]));

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
 * ���ʱ���Ƶ㣬����ʱ���Ʊ�
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