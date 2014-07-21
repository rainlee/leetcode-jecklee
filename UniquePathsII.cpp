/***
 * 同Unique Paths, DP
 * 可以用一维的dp[]解决
 * 每次判断当前是不是障碍物就可以了
 ***/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if ((0 == obstacleGrid.size()) || (0 == obstacleGrid[0].size()))
            return 0;
        if (1 == obstacleGrid[0][0])  // obstacle at (0,0)
            return 0;
            
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((0 == i) && (0 == j))
                    continue;
                if (1 == obstacleGrid[i][j])
                    dp[j] = 0;
                else
                    dp[j] = ((i > 0) ? dp[j] : 0) + ((j > 0) ? dp[j-1] : 0);
            }
        }
        return dp[n-1];
    }
};