/***
 * DP - 쳲���������
 * dp[i] ��ʾ����i·����������i��������Դ
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
 * ��2��DP + ����
 * ��һ������pre��¼dp[i-1], cur ��¼dp[i]
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
 * ��3��ת�ƾ��� A = [(1,1), (1,0)]
 *      {f(n), f(n-1), f(n-1), f(n-2)} ={1, 1, 1, 0}^(n-1)
 *      ����ĳ˷������ö��ַ����㣬ʱ�临�Ӷ�O(logn)
 * ��4��ͨ�ʽΪ:{[(1+��5) / 2]^n - [(1����5) / 2]^n }/��5
 ***/
class Solution {
public:
    int climbStairs(int n) {
        const double  s = sqrt(5);
        return floor((pow((1+s)/2, n+1) - pow((1-s)/2, n+1)) / s);
    }
};