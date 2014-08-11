/***
 * DFS
 * ͬSubsets����Ҫȥ��
 * ��ǰ����ǰһ����ȣ���ǰһ��ûѡ����ǰ���Ҳ����ѡ
 * ���������򡭡�
 ***/
/*
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        
        std::sort(S.begin(), S.end());
        
        vector<int> path;
        dfs(S, 0, path);
        
        return vvsets;
    }
private:
    vector<vector<int> > vvsets;
    
    void dfs(const vector<int> &S, int deep, vector<int> &path)
    {
        if (deep == S.size())
        {
            vvsets.push_back(path);
            return;
        }
        
        // choose
        path.push_back(S[deep]);
        dfs(S, deep+1, path);
        path.pop_back();
        
        // dont choose
        while ((deep < S.size()-1) && (S[deep+1] == S[deep])) // not choose S[deep], so cant choose S[deep+1]
            ++deep;
        
        dfs(S, deep+1, path);
        
        return;
    }
};
*/

/***
 * ��2����һ�ֵݹ鷽��
 * ע�⣺1 ȥ��, 2 ����ѡ�����
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