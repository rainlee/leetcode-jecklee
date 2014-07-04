/***
 * 法1：递归 + 剪枝 枚举分割点  O(n^6)?
 * 可能的分割点：1 ~ len-1
 * 对每个分割点，有镜像和不镜像两种情况，分别递归
 * 剪枝：
 * 对每种情况，首先检查s1 s2是否相同，若相同直接返回true
 * 否则，统计每个字母，字母个数相同，继续分割
 ***/
/*
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        
        if (s1 == s2)     // O(n)
            return true;
        
        // cnt each alpha
        int cnt[26] = {0};
        for (int i = 0; i < s1.size(); ++i)
            ++cnt[s1[i] - 'a'];
        for (int i = 0; i < s2.size(); ++i)
            --cnt[s2[i] - 'a'];
        for (int i = 0; i < 26; ++i)
            if (0 != cnt[i])
                return false;
            
        // enum the pos of partition
        for (int i = 1; i < s1.size(); ++i)
            if ( (isScramble(s1.substr(0, i), s2.substr(0, i)) &&          // same
                  isScramble(s1.substr(i), s2.substr(i))) ||
                 (isScramble(s1.substr(0, i), s2.substr(s2.size()-i)) &&   // symmetric
                  isScramble(s1.substr(i), s2.substr(0, s2.size()-i))) )
                return true;
        return false;
    }
};
*/

/***
 * 法2：动态规划
 * dp[k][i][j] 表示 s1从i开始k个字符 与 s2从j开始k个字符 是否为 scrambled string
 *              / (s1[i] == s2[j]), k=1
 * dp[k][i][j] =                   枚举分割点l(1 <= l <= k-1)，分左右不翻转和翻转两种情况讨论
 *              \ (dp[l][i][j] && dp[k-l][i+l][j+l]) || ((dp[l][i][j+k-l] && dp[k-l][i+l][j]))
 * 时间复杂度O(n^3)?
 ***/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        
        if (s1 == s2)     // O(n)
            return true;
    
        int n = s1.size();
        
        vector<vector<vector <bool> > > dp(n+1, vector<vector<bool> >(n, vector<bool>(n, false)));  // k: 1~n
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[1][i][j] = (s1[i] == s2[j]);
        
        for (int k = 2; k <= n; ++k)
        {
            for (int i = 0; i <= n-k; ++i)
            {
                for (int j = 0; j <= n-k; ++j)
                {
                    for (int l = 1; l < k; ++l)  // enum the partition point
                    {
                        if ( (dp[l][i][j] && dp[k-l][i+l][j+l]) || ((dp[l][i][j+k-l] && dp[k-l][i+l][j])) )
                        {
                            dp[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};