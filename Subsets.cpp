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

/***
 * 法3：模拟加法
 * 1表示选，0表示不选，则0 ~ 2^n-1 则刚好对应子集
 * 直接将相应的数转换成子集就可以了
 * 注意先排序
 ***/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        const int n = S.size();
        int maxn = 1 << n;
        for (int i = 0; i < maxn; ++i)
            convertIntToSet(i, S);
        return vsets;
    }
private:
    vector<vector<int> > vsets;
    void convertIntToSet(int k, vector<int> &S)
    {
        vector<int> set;
        int index = 0;    // index in S
        for (int i = k; i > 0; i >>= 1)
        {
            if (i & 0x1)  // 1 means choose
                set.push_back(S[index]);
            ++index;
        }
        vsets.push_back(set);
    }
};