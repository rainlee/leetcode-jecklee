/***
 * 动态规划
 * dp[i][j] 表示s3 的前 i+j 个字符是否能由s1的前i个和s2的前j个字符组成
 *            / dp[i-1][j], if s1[i-i] == s3[i+j-1]
 * dp[i][j] = 
 *            \ dp[i][j-1], if s2[j-i] == s3[i+j-1]
 ***/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ((s1.size() + s2.size()) != s3.size())
            return false;
        if (0 == s1.size())
            return (s3.compare(s2) == 0);
        if (0 == s2.size())
            return (s3.compare(s1) == 0);
        
        vector<vector<bool> > dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= s1.size(); ++i)
        {
            for (int j = 0; j <= s2.size(); ++j)
            {
                if ((0 == i) && (0 == j))
                    continue;
                else if (0 == i)
                    dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);
                else if (0 == j)
                    dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
                else
                    dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[i+j-1])) || 
                               (dp[i-1][j] && (s1[i-1] == s3[i+j-1]));
            }
        }
        return dp[s1.size()][s2.size()];
    }
};