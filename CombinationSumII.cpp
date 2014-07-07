/***
 * DFS
 * 同Combination Sum
 * 不同的是每个数只能选一次，若当前数等于前一个数，而前一个数又没有选，则当前数也不能选
 ***/
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        
        std::sort(num.begin(), num.end());
        
        vector<int> path;
        dfs(num, target, 0, path);
        
        return vvcoms;
    }
private:
    vector<vector<int> > vvcoms;
    
    void dfs(const vector<int> &num, int target, int start, vector<int> &path)
    {
        if (0 == target)
        {
            vvcoms.push_back(path);
            return;
        }
        for (int i = start; (i < num.size()) && (target >= num[i]); ++i)
        {
            if ((i > start) && (num[i] == num[i-1]))  // not choose num[i-1]
                continue;
            
            path.push_back(num[i]);
            dfs(num, target-num[i], i+1, path);  // i+1, check next num
            path.pop_back();
        }
        return;
    }
};