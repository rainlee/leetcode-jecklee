/***
 * DFS
 * 从前往后取k个数
 ***/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> path;
        dfs(k, 1, n, path);
        
        return vvcoms;
    }
private:
    vector<vector<int> > vvcoms;
    
    void dfs(int deep, int start, int n, vector<int> path)
    {
        if (0 == deep)
        {
            vvcoms.push_back(path);
            return;
        }
        
        for (int i = start; i <= n-deep+1; ++i)  // right bound
        {
            path.push_back(i);
            dfs(deep-1, i+1, n, path);  // i+1, next
            path.pop_back();
        }
    }
};