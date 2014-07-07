/***
 * 动态规划
 * dp[i] 表示s中的前i个能否用dict表示
 * 然后枚举i之前以i结尾的子串[j,i+1]是否属于dict && dp[j]是否能用dict表示
 * dp[i] = U{dp[j] && s.substring[j, i+1] E dict, j E [0, i) }
 ***/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        const int n = s.size();
        vector<bool> dp(n+1, false);  // 0 - n
        
        dp[0] = true;
        for (int i = 1; i <= n; ++i)  // len
        {
            for (int j = i-1; j >= 0; --j)
            {
                dp[i] = dp[j] && (dict.find(s.substr(j, i-j)) != dict.end());
                if (dp[i])
                    break;
            }
        }
        return dp[n];
    }
};