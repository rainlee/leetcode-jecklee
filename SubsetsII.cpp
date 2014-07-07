/***
 * DFS
 * ͬSubsets����Ҫȥ��
 * ��ǰ����ǰһ����ȣ���ǰһ��ûѡ����ǰ���Ҳ����ѡ
 * ���������򡭡�
 ***/
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