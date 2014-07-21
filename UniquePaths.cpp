/***
 * 法1：DP
 * dp[i][j]表示到(i,j)的路径个数
 * dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * x y轴上的只能有一个来源
 * 初始化dp[[0][0] = 1 
 ***/
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if ((0 != i) || (0 != j))
                    dp[i][j] = ((i > 0) ? dp[i-1][j] : 0) + ((j > 0) ? dp[i][j-1] : 0);
        
        return dp[m-1][n-1];
    }
};
*/

/***
 * 法2：DP 优化空间
 * 递推时，每次只会用到前一行的数据
 * 所以只需要保存两行就行了，每次切换
 * 时间复杂度O(m*n)，空间O(n)
 ***/
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(2, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if ((0 != i) || (0 != j))
                    dp[i%2][j] = ((i > 0) ? dp[1 - i%2][j] : 0) + ((j > 0) ? dp[i%2][j-1] : 0);
        return dp[1-m%2][n-1];
    }
};
*/

/***
 * 法3：DP 进一步优化空间
 * 只用一行dp[j]
 * dp[j] = dp[j] + dp[j-1]
 * 左边的dp[j]就是上一行的值，dp[j-1]是上一列的值
 ***/
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[j] = dp[j] + dp[j-1];
        return dp[n-1];
    }
};
*/

/***
 * 法4：排列组合
 * 共(m+n-2)步中，跳出n-1步往右走
 * C(m+n-2)(n-1)
 * 使用公式 C(x,t) = t!/(x!*(t-x)!) , x应该尽量大，减少计算量
 ***/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int t = (m-1) + (n-1);
        int x = max(m-1, n-1);
        
        long long sum = 1;
        for (int i = t; i > x; --i)
            sum *= i;
        for (int i = t-x; i >= 1; --i)
            sum /= i;
            
        return sum;
    }
};