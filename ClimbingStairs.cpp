/***
 * DP - 斐波拉切数列
 * dp[i] 表示到达i路径数，到达i有两个来源
 * dp[i] = dp[i-1] + dp[i-2], i E [0, n]
 ***/
/*
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0)
            return 0;
            
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
*/

/***
 * 法2：DP + 滚动
 * 用一个变量pre记录dp[i-1], cur 记录dp[i]
 ***/
/*
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0)
            return 0;
        int pre = 1;
        int cur = 1;
        for (int i = 2; i <= n; ++i)
        {
            int tmp = cur;
            cur += pre;     // DP
            pre = tmp;
        }
        return cur;
    }
};
*/

/***
 * 法3：转移矩阵 A = [(1,1), (1,0)]
 *      {f(n), f(n-1), f(n-1), f(n-2)} ={1, 1, 1, 0}^(n-1)
 *      矩阵的乘方可以用二分法计算，时间复杂度O(logn)
 * 法4：通项公式为:{[(1+√5) / 2]^n - [(1－√5) / 2]^n }/√5
 ***/
class Solution {
public:
    int climbStairs(int n) {
        const double  s = sqrt(5);
        return floor((pow((1+s)/2, n+1) - pow((1-s)/2, n+1)) / s);
    }
};