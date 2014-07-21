/***
 * DFS
 * 用一个数组标记某个数是否被使用
 * 如果没被使用，则可以使用
 * 时间复杂度O(n!) 空间复杂度O(n)
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