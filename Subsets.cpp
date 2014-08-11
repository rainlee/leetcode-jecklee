/***
 * DFS
 * 遍历S，对每一个数字有两种情况，选 or 不选
 * 先排序！
 ***/
/*
 class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        
        std::sort(S.begin(), S.end());
        
        vector<int> path;
        dfs(S, 0, path);
        
        return vvsets;
    }
private:
    vector<vector<int> > vvsets;
    
    void dfs(vector<int> &S, int deep, vector<int> &path)
    {
        if (deep == S.size())
        {
            vvsets.push_back(path);
            return;
        }
        
        // choose S[deep]
        path.push_back(S[deep]);
        dfs(S, deep+1, path);
        path.pop_back();
        
        // dont choose S[deep]
        dfs(S, deep+1, path);
        
        return;
    }
};
*/

/***
 * 法2：另一种递归方法
 * 在每一层上的可选范围是[start, s.size())
 * 注意处理在该层上什么都不选的情况
 ***/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> path;
        subsRec(S, 0, path);
        return vsets;
    }
private:
    vector<vector<int> > vsets;
    
    void subsRec(vector<int> &s, int start, vector<int> &path)
    {
        if (start == s.size())
        {
            vsets.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); ++i)
        {
            path.push_back(s[i]);
            subsRec(s, i+1, path);
            path.pop_back();
        }
        subsRec(s, s.size(), path);   // choose nothing in this level
        return;
    }
};