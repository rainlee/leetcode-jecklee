/***
 * DFS
 * ������Ȼ��ǰ����ѡ����ֱ�� sum >= target
 * ע�⣺ͬһ���������ظ�ѡ������ÿ�ζ���ͷ��ʼѡ
 ***/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        
        std::sort(candidates.begin(), candidates.end());
        
        vector<int> path;
        dfs(candidates, target, 0, path);
        
        return vvcoms;
    }
private:
    vector<vector<int> > vvcoms;
    
    void dfs(vector<int> &cands, int target, int start, vector<int> &path)
    {
        if (0 == target)
        {
            vvcoms.push_back(path);
            return;
        }
        for (int i = start; (i < cands.size()) && (target >= cands[i]); ++i)  // if target < cans[i], break and return
        {
            path.push_back(cands[i]);
            dfs(cands, target-cands[i], i, path);   // i not i+1, can choose multi times
            path.pop_back();
        }
        return;
    }
};