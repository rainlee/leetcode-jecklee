/***
 * DFS
 * ͬCombination Sum
 * ��ͬ����ÿ����ֻ��ѡһ�Σ�����ǰ������ǰһ��������ǰһ������û��ѡ����ǰ��Ҳ����ѡ
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