/***
 * ͬWord Break��ʹ��DP
 * ����dpf[i]����ǰi�Ƿ�ɷֵ�ͬʱ����dpw[i][j]��¼��s[j,i)�Ƿ�����dict
 * ���ǺϷ��ʣ�����Դ�j���Ͽ�
 * Ȼ��ʹ��DFS����dpw[i][j]���Ӻ���ǰ��¼·��
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