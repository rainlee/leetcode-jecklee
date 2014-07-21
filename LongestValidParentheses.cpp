/***
 * 法1：栈
 * 栈中存放的是尚未被匹配的'('的索引
 * 当s[i] == '('，入栈
 * 当s[i] == ')'，而栈非空时，匹配，出栈，此时栈顶的元素是尚未被匹配的，
 *     栈顶到i之间的都已经匹配，匹配长度为i - s.top()
 *     若栈为空，说明完全匹配，此时匹配长度为i - last（last是上一个失配点）
 *               比如()()，第二个')'时，last = 0，匹配长度是4不是2
 * 当s[i] == ')'，而栈为空时，失配，记录last
 ***/
/*
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> spare;   // save index
        
        int last = -1;  // first mismatch pos
        int maxl = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                spare.push(i);
            else
            {
                if (spare.empty())  // mismatch
                    last = i;
                else
                {
                    spare.pop();    // match
                    maxl = max(maxl, spare.empty() ? (i - last) : (i - spare.top()));
                }
            }
        }
        return maxl;
    }
};
*/

/***
 * 法2：DP
 * dp[i]表示从s[i]到s[n - 1]包含s[i]的最长的有效匹配括号子串长度
 * 初始化dp[n-1] = 0
 * i从n - 2 -> 0逆向求dp[]，并记录其最大值。
 * 若s[i] == '('，则在s中从i开始到n - 1计算dp[i]的值。这个计算分为两步：
 *  - 在s中寻找从i + 1开始的有效括号匹配子串长度，即dp[i + 1]，跳过这段有效的括号子串，查看下一个字符，
 *    其下标为j = i + 1 + dp[i + 1]。若j没有越界，并且s[j] == ‘)’，则s[i ... j]为有效括号匹配，dp[i] =dp[i + 1] + 2
 *  - 在求得了s[i ... j]的有效匹配长度之后，若j + 1没有越界，则dp[i]的值还要加上从j + 1开始的最长有效匹配，即dp[j + 1]。
 *    比如，(())()
 ***/
/*
class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        vector<int> dp(n, 0);
        
        int maxl = 0;
        for (int i = n-2; i >= 0; --i)
        {
            int j = i + dp[i+1] + 1;   // index matched with i
            if ((s[i] == '(') && (j < n) && (s[j] == ')'))   // [i, ..., j]match
            {
                dp[i] = dp[i+1] + 2;
                if (j + 1 < n)       // maybe match
                    dp[i] += dp[j+1];
                maxl = max(maxl, dp[i]);
            }
        }
        return maxl;
    }
};
*/

/***
 * 法3：DP 同法2
 * 从前往后算，dp[i]表示s[0, i]的最长匹配长度
 ***/
class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        vector<int> dp(n, 0);
        
        int maxl = 0;
        for (int i = 1; i < n; ++i)
        {
            int j = i - dp[i-1] - 1;
            if ((s[j] == '(') && (j >= 0) && (s[i] == ')'))  // match
            {
                dp[i] = dp[i-1] + 2;
                if (j - 1 >= 0)
                    dp[i] += dp[j-1];
                maxl = max(maxl, dp[i]);
            }
        }
        return maxl;
    }
};