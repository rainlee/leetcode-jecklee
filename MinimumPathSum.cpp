/***
 * DP
 * dp[i][j] 表示从(0,0)到(i,j)的最小路径值
 * dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j]
 * 注意考虑边界
 ***/
/*
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
            
        const int m = grid.size();
        const int n = grid[0].size();
        
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((0 == i) && (0 == j))
                    dp[i][j] = grid[i][j];
                else if (0 == i)
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                else if (0 == j)
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[m-1][n-1];
    }
};
*/

/***
 * 法2：DP + 滚动数组
 * 只用记录相邻的两行，而可以通过一个一维的数组实现
 * dp[j] = min(dp[j-1], dp[j]) + grid[i][j]
 * dp[j-1]表示左边一格，dp[j]表示上边一格
 ***/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        
        const int m = grid.size();
        const int n = grid[0].size();
        
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((0 == i) && (0 == j))
                    dp[j] = grid[i][j];
                else if (0 == i)
                    dp[j] = grid[i][j] + dp[j-1];
                else if (0 == j)
                    dp[j] = grid[i][j] + dp[j];
                else
                    dp[j] = grid[i][j] + min(dp[j-1], dp[j]);
            }
        }
        return dp[n-1];
    }
};