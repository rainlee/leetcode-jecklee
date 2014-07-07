/***
 * DFS
 * ����S����ÿһ�����������������ѡ or ��ѡ
 * ������
 ***/
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
        
        // dont choost S[dee[]
        dfs(S, deep+1, path);
        
        return;
    }
};