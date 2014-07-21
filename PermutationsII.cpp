/***
 * DFS, 同Permutations
 * 去重，当num[i] == num[i-1]时，如果i-1没有排，则i也不能排
 * 注：需要先排序
 ***/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vused.resize(num.size(), false);
        sort(num.begin(), num.end());     // sort first
        vector<int> path;
        dfs(num, path);
        return vvpers;
    }
private:
    vector<vector<int> > vvpers;
    vector<bool> vused;
    
    void dfs(vector<int> &num, vector<int> &path)
    {
        if (path.size() == num.size())
        {
            vvpers.push_back(path);
            return;
        }
        
        for (int i = 0; i < num.size(); ++i)
        {
            if ((i > 0) && (num[i] == num[i-1]) && (!vused[i-1]))  // cant choose
                continue;
            if (!vused[i])
            {
                vused[i] = true;
                path.push_back(num[i]);
                dfs(num, path);         // next step
                path.pop_back();        // back tracking
                vused[i] = false;
            }
        }
        return;
    }
};