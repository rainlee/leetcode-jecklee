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
 * 最长回文子序列，可以得到逆序串t，然后s t用DP求最长公共子序列
 * 最长回文子串
 * 可以枚举回文中点，然后向左右扩展
 * 注意可能是奇数对称，也可能是偶数对称
 * 时间复杂度O(n^2)
 ***/
/*
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        
        maxl = 1;
        wstart = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            searchPal(s, 1, i-1, i+1);  // odd
            searchPal(s, 0, i-1, i);    // even
        }
        return s.substr(wstart, maxl);
    }
private:
    void searchPal(string &s, int len, int low, int high)
    {
        while ((low >= 0) && (high < s.size()) && (s[low] == s[high]))  // odd
        {
            len += 2;
            --low;
            ++high;
        }
        if (len > maxl)
        {
            maxl = len;
            wstart = low + 1;
        }
        return;
    }

    int maxl = 1;
    int wstart = 0;
};
*/

/***
 * 法2：动态规划
 * dp[i][j] 表示 i到j是否是回文 (j >= i)
 * dp[i][j] = dp[i+1][j-1] && (s[i] == s[j])
 * 初始化i == j时 dp[i][j] = true; 
 * j = i+1, dp[i][j] = (s[i] == s[j])
 * i > j 时，相当于空串，也认为是回文，dp[i][j] = true
 * 时间复杂度 O(n^2)
 ***/
/*
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        if (n <= 1)
            return s;
        
        //vector<vector<bool> > dp(s.size(), vector<bool>(false));
        bool dp[n][n];   // vector 会超时？！
        fill_n(&dp[0][0], n*n, false);
        //for (int i = 0; i < s.size(); ++i)
        //    dp[i][i] = true;
        
        int maxl = 1;
        int wstart = 0;
        for (int j = 0; j < s.size(); ++j)
        {
            dp[j][j] = true;
            for (int i = 0; i < j; ++i) // [i, j]
            {
                if (j == i+1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = ((s[i] == s[j]) && dp[i+1][j-1]);
                if (dp[i][j])
                {
                    int len = j - i + 1;
                    if (len > maxl)
                    {
                        maxl = len;
                        wstart = i;
                    }
                }
            }
        }
        return s.substr(wstart, maxl);
    }
};
*/

// 动规，时间复杂度O(n^2)，空间复杂度O(n)
// 滚动数组，优化空间
// vector会超时……
/*
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        const int n = s.size();
        //vector<bool> dp(n, false);
        bool dp[n];
        fill_n(&dp[0], n, false);
        int maxl = 0;
        int istart = 0;
        for (int i = 0; i < n; ++i)
        {
            dp[i] = true;
            for (int j = 0; j < i; ++j)
            {
                if (j == i - 1)
                    dp[j] = (s[i] == s[j]);
                else
                    dp[j] = dp[j+1] && (s[i] == s[j]);
                if (dp[j])
                {
                    int len = i - j + 1;
                    if (len > maxl)
                    {
                        maxl = len;
                        istart = j;
                    }
                }
            }
        }
        return s.substr(istart, maxl);
    }
};
*/

/***
 * 法3：O(n)的算法 http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
 * 思路和法1一样，枚举回文中点，向左右扩展
 * 用数组P[i]记录以i为中心的最长回文串的长度，利用P[i]的回文对称性避免一些重复计算
 * 为方便处理奇数/偶数对称的情况，在收尾及每两个字符中间插入一个特殊字符'#'
 * #b#a#b# 和 #b#a#a#b# 全部变为奇数对称
 * P[3] = 3   P[4] = 4 回文一半的长度刚好等于去掉'#'的全部回文长度
 * 从前往后遍历求P[i], 并记录回文最右边界R，对应的中点C
 * 若 R > i, 则i在以C为中点的对称位置i_m有个对称点
 *   并且i的右边长R - i的部分 和 i_m的左边长R-i的部分对称
 *     若P[i_m] <= R-i, 则关于i_m的对称点 全在以i为中点R-i为半径的回内
 *       i_m的对称点也有同样的特征，P[i] 至少等于P[i_m]，然后再向左右扩展
 *     若P[i_m] > R-i，则 P[i]至少等于R-i，然后向左右扩展
 * 若R <= i, 则P[i]从0开始扩展
 ***/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        
        string t = preProcess(s);
        const int n = t.size();
        
        vector<int> P(n, 0);
        int C = 0;
        int R = 0;
        int maxl = 0;
        int maxi = 0;
        for (int i = 1; i < n-1; ++i)
        {
            int i_m = 2*C - i;   // mirror
            
            P[i] = (R > i) ? min(P[i_m], R-i) : 0;
            
            while (t[i + P[i] + 1] == t[i - P[i] - 1])  // expand
                ++P[i];
            
            if (P[i] > maxl)  // mark the max len
            {
                maxl = P[i];
                maxi = i;
            }
            
            if (i + P[i] > R)  // mark the rightest index
            {
                C = i;
                R = i + P[i];
            }
        }
        return s.substr((maxi - 1 - maxl)/2, maxl);
    }
private:
    string preProcess(const string &s)
    {
        const int n = s.size();
        if (0 == n)
            return "^$";
        string t = "^";
        for (int i = 0; i < n; ++i)
            // t += "#" + (char)s[i];  // error
            t += "#" + s.substr(i, 1);
        t += "#$";
        return t;
    }
};