/***
 * 贪心法，低进高出
 * prices[i] > prices[i-1], 则i-1买进，i卖出
 * 求出所有相正差的累加和
 ***/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxp = 0;
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i] > prices[i-1])
                maxp += (prices[i] - prices[i-1]);
        return maxp;
    }
};