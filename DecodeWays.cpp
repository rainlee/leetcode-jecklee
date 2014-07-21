/***
 * DP 类似Climbing Stairs
 * dp[i]表示s的前i个字符有多少种解码方式
 *       / dp[i-1] + dp[i-2], if 10 < s[i-2]s[i-1] <= 26 except 20
 * dp[i] =
 *       \ dp[i-1], else
 * 注意10 和 20 的处理，都只有一种解码方式
 ***/
/*
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || (s[0] == '0'))
            return 0;
        const int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;   // init
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            int num = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (s[i-1] == '0')
            {
                if ((s[i-2] == '1') || (s[i-2] == '2'))  // "10" "20"
                    dp[i] = dp[i-2];
                else             // 30 40 ...
                    return 0;
            }
            else if ((num > 10) && (num <= 26))
                dp[i] = dp[i-1] + dp[i-2];
            else
                dp[i] = dp[i-1];
        }
        return dp[n];
    }
};
*/

/***
 * 法2：DP + 滚动
 * 优化空间
 * 用两个变量pre cur分别记录上一个和当前的解码个数
 * 分别对应dp[i-1] dp[i-2]
 ***/
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || (s[0] == '0'))
            return 0;
        const int n = s.size();
        
        int pre = 1;
        int cur = 1;
        for (int i = 2; i <= n; ++i)
        {
            int tmp = cur;     // save cur
            if (s[i-1] == '0')
            {
                if ((s[i-2] == '1') || (s[i-2] == '2'))  // "10" "20"
                    cur = pre;     // cur = pre + cur = pre (dp[i-2])
                else               // 30 40 ...
                    return 0;
            }
            else if ((s[i-2] == '1') || ((s[i-2] == '2') && (s[i-1] <= '6'))) // 11 ~ 19 ~ 26
                cur += pre;        // cur = pre + cur
            // else cur = cur;     // cur = pre + cur = cur (dp[i-1])
            pre = tmp;
        }
        return cur;
    }
};