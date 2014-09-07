/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         God Bless Me     BUG Free Forever
*/
/***
 * DP
 * 重要的是找到转移方程
 * 设f[i][j]表示 T的前j个字符 在 S的前i个字符 中出现的次数，则
 *           / 0, i = 0 || j = 0
 * f[i][j] = - f[i-1][j], (S[i] != T[j]) 只需要比较S的前i-1个 和 T的前j个
 *           \ f[i-1][j] + f[i-1][j-1], (S[i] == T[j]) 使用S[i] || 不使用
 * 长度0~n，注意dp[]长n+1
 ***/
/*
class Solution {
public:
    int numDistinct(string S, string T) {
        const int n1 = S.size();
        const int n2 = T.size();
        vector<vector<int> > dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                dp[i][j] += dp[i-1][j];
                if (S[i-1] == T[j-1])
                    dp[i][j] += (j == 1) ? 1 : dp[i-1][j-1];  // j=1, the first char
            }
        }
        return dp[n1][n2];
    }
};
*/

/***
 * 法2：DP + 滚动数组
 ***/
/*
class Solution {
public:
    int numDistinct(string S, string T) {
        const int n1 = S.size();
        const int n2 = T.size();
        vector<int> dp(n2+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n1; ++i)
        {
            int upper_left = dp[0];
            for (int j = 1; j <= n2; ++j)
            {
                int upper = dp[j];
                if (S[i-1] == T[j-1])
                    dp[j] += upper_left;
                upper_left = upper;
            }
        }
        return dp[n2];
    }
};
*/

/***
 * 法3：DP + 滚动数组
 * 为防止dp[i-1][j-1]被覆盖，每行从后往前滚动
 ***/
class Solution {
public:
    int numDistinct(string S, string T) {
        const int n1 = S.size();
        const int n2 = T.size();
        vector<int> dp(n2+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n1; ++i)
            for (int j = n2; j > 0; --j)
                if (S[i-1] == T[j-1])
                    dp[j] += dp[j-1];    // dp[j-1] is upper_left
        return dp[n2];
    }
};

// DP 注意数组是n 还是n+1
// dp[i][j]表示S[0, i) 和 T[0, j) 有多少种匹配方式
//           / dp[i-1][j], S[i] != T[j]
// dp[i][j] = 
//           \ dp[i-1][j-1] + dp[i-1][j], S[i] == T[j]
/*
class Solution {
public:
    int numDistinct(string S, string T) {
        if (S.empty() || T.empty())
            return 0;
        const int n = S.size();
        const int m = T.size();
        vector<vector<int> > dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                dp[i][j] = (0 == i) ? 0 : dp[i-1][j];
                if (S[i] == T[j])
                    dp[i][j] += (0 == j) ? 1 : ((0 == i) ? 0 : dp[i-1][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
*/

class Solution {
public:
    int numDistinct(string S, string T) {
        if (S.empty() || T.empty())
            return 0;
        const int n = S.size();
        const int m = T.size();
        vector<int> dp(m, 0);
        for (int i = 0; i < n; ++i)
            for (int j = m-1; j >= 0; --j)
                if (S[i] == T[j])
                    dp[j] += (0 == j) ? 1 : dp[j-1];
        return dp[m-1];
    }
};