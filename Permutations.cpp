/***
 * DFS
 * ��һ��������ĳ�����Ƿ�ʹ��
 * ���û��ʹ�ã������ʹ��
 * ʱ�临�Ӷ�O(n!) �ռ临�Ӷ�O(n)
 ***/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vused.resize(num.size(), false);
        vector<int> path;
        dfs(num, path);
        return vvpers;
    }
private:
    vector<vector<int> > vvpers;
    vector<bool> vused;
    
    void dfs(vector<int> &num, vector<int> &path)
    {
        if (path.size() == num.size())  // the end
        {
            vvpers.push_back(path);
            return;
        }
        
        for (int i = 0; i < num.size(); ++i)
        {
            if (!vused[i])  // available
            {
                vused[i] = true;
                path.push_back(num[i]);
                dfs(num, path);          // next deep
                path.pop_back();         // back tracking
                vused[i] = false;
            }
        }
        return;
    }
};