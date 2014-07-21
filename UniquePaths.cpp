/***
 * ��1��DP
 * dp[i][j]��ʾ��(i,j)��·������
 * dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * x y���ϵ�ֻ����һ����Դ
 * ��ʼ��dp[[0][0] = 1 
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
 * ��2��DP �Ż��ռ�
 * ����ʱ��ÿ��ֻ���õ�ǰһ�е�����
 * ����ֻ��Ҫ�������о����ˣ�ÿ���л�
 * ʱ�临�Ӷ�O(m*n)���ռ�O(n)
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
 * ��3��DP ��һ���Ż��ռ�
 * ֻ��һ��dp[j]
 * dp[j] = dp[j] + dp[j-1]
 * ��ߵ�dp[j]������һ�е�ֵ��dp[j-1]����һ�е�ֵ
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
 * ��4���������
 * ��(m+n-2)���У�����n-1��������
 * C(m+n-2)(n-1)
 * ʹ�ù�ʽ C(x,t) = t!/(x!*(t-x)!) , xӦ�þ����󣬼��ټ�����
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