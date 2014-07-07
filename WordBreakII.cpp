/***
 * 同Word Break，使用DP
 * 在用dpf[i]记下前i是否可分的同时，用dpw[i][j]记录下s[j,i)是否属于dict
 * 若是合法词，则可以从j处断开
 * 然后使用DFS遍历dpw[i][j]，从后往前记录路径
 ***/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        const int n = s.size();
        
        vector<bool> dpf(n+1, false);
        vector<vector<bool> > dpw(n+1, vector<bool>(n, false));
        
        dpf[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (dpf[j] && (dict.find(s.substr(j, i-j)) != dict.end()))
                {
                    dpf[i] = true;
                    dpw[i][j] = true;
                }
            }
        }
        
        if (!dpf[n])  // not found
            return vpaths;
        
        vector<string> vpath;
        genPath(s, dpw, n, vpath);
        
        return vpaths;
    }
private:
    vector<string> vpaths;
    
    void genPath(const string &s, vector<vector<bool> > &dpw, int end, vector<string> &vpath)
    {
        if (0 == end)  // find a full path
        {
            string stmp("");
            stmp += vpath[vpath.size()-1];
            for (int i = vpath.size()-2; i >= 0; --i)
                stmp += " " + vpath[i];
            vpaths.push_back(stmp);
            return;
        }
        
        for (int j = 0; j < end; ++j)  // enum the split point before end
        {
            if (dpw[end][j])  // can break here
            {
                vpath.push_back(s.substr(j, end-j));   // get new word
                genPath(s, dpw, j, vpath);
                vpath.pop_back();    // restore
            }
        }
        return;
    }
};