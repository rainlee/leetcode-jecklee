/***
 * 从左往右遍历一遍
 * 记下最小值minp，求当天卖出的最大收益prices[i] - minp
 * 时间复杂度O(n)
 ***/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minp = INT_MAX;
        int maxp = 0;
        
        for (int i = 0; i < prices.size(); ++i)
        {
            minp = min(minp, prices[i]);
            maxp = max(maxp, prices[i] - minp);
        }
        return maxp;
    }
};