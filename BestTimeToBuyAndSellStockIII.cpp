/***
 * 最多两次交易，动态规划 DP
 * 以i分界，左边的最大交易为maxpl[i]，右边的最交易为maxpr[i]
 * 则i位置的最大交易为maxpl[i] + maxpr[i]，保留所有i的最大交易值
 * maxpl[], 从左到右遍历求得
 * maxpr[], 从右到左遍历求得
 * 为节省空间，只求出maxpr[]，maxpl只用一个变量保存，从左到右遍历时更新
 * 时间复杂度O(n)，空间复杂度O(n)
 ***/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int n = prices.size();
        if (n < 2)
            return 0;
        
        // right -> left
        vector<int> maxpr(n, 0);  // max right profit
        int maxvr = prices[n-1];  // max right price(value)
        for (int i = n-2; i >= 0; --i)
        {
            maxvr = max(maxvr, prices[i]);
            maxpr[i] = max(maxpr[i+1], maxvr - prices[i]);  // DP
        }
        
        // left -> right
        int maxp = 0;         // max profit in total
        int maxpl = 0;        // max left profit, will be updated when foreach
        int minvl = INT_MAX;  // min left price
        for (int i = 0; i < n; ++i)
        {
            minvl = min(minvl, prices[i]);
            maxpl = max(maxpl, prices[i] - minvl);   // DP
            maxp = max(maxp, maxpl + maxpr[i]);
        }
        return maxp;
    }
};