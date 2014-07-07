/***
 * 动态规划DP
 * dpc[i] 用来表示[i,n)之间最小cut
 * 初始化：最坏情况下 切分为单个单词
 * dpc[i] = min{dpc[j+1] + 1}, j E [i, n)
 * 从j切一刀，分为两块 [i, j] [j+1, n)
 * 判断子串是否回文也用DP，参见Palindrome Partitioning
 * dpb[i][j] = (s[i] == s[j]) && ((j-i < 2) || dpb[i+1][j-1]), i E [0, n), j E [i, n)
 * 从后往前计算
 ***/
class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
        
        //vector<int> dpc(n + 1);
        vector<int> dpc(n);
        vector<vector<bool> > dpb(n, vector<bool>(n, false));
        
        //dpc[n] = -1;  // can not be cut
        for (int i = n-1; i >= 0; --i)
        {
            dpc[i] = n - 1 - i;  // init, the worst case is cutting by each char
            for (int j = i; j < n; ++j)
            {
                dpb[i][j] = (s[i] == s[j]) && ((j-i < 2) || dpb[i+1][j-1]);
                if (dpb[i][j])  // can cut here
                    dpc[i] = (j == n-1) ? 0 : min(dpc[i], dpc[j+1] + 1);  // need not be cut
            }
        }
        return dpc[0];
    }
};