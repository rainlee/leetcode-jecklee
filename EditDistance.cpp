/***
 * DP
 * 定义d[i, j] 表示word1的前i个字符和word2的前j个字符的最小编辑距离
 * 则i字符串有3种途径变为j
 *           / d[i-1, j-1], word1[i] == word2[j]
 *           / d[i-1, j] + 1, delete, word2删掉i字符
 * d[i, j] = - d[i, j-1] + 1, insert, word2插入j字符
 *           \ d[i-1, j-1] + 1, replace, word1[i] != word2[j]
 * 初始化 d[0, j] = j; d[i, 0] = i
 * 注：字符长度从0~n，所以dp[]长 n+1
 ***/
/*
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        vector<vector<int> > dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 0; i <= n1; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= n2; ++j)
            dp[0][j] = j;
        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                if (word1[i-1] == word2[j-1])  // caution: index i-1
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
            }
        }
        return dp[n1][n2];
    }
};
*/

/***
 * 法2：DP + 滚动数组
 * 只需要记录相邻两行数据，用一维数组实现
 * 需要记录的值d[i, j-1] d[i-1, j] d[i-1, j-1]
 * 前两个都可以复用数组，d[i-1, j-1]需要额外的变量记录
 * upper_left  upper
 *  dp[j-1]    dp[j]
 ***/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        vector<int> dp(n2+1, 0);   // rolling array
        for (int j = 0; j <= n2; ++j)
            dp[j] = j;
        
        for (int i = 1; i <= n1; ++i)
        {
            int upper_left = dp[0];  // caution!!! save dp[i-1][j-1]
            dp[0] = i;               // init dp[i][0]
            for (int j = 1; j <= n2; ++j)
            {
                int upper = dp[j];   // upperleft for next j
                if (word1[i-1] == word2[j-1])
                    dp[j] = upper_left;
                else
                    dp[j] = min(min(dp[j], dp[j-1]), upper_left) + 1;
                upper_left = upper;  // update for next j
            }
        }
        return dp[n2];
    }
};