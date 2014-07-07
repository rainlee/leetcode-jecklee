/***
 * ������ν��ף���̬�滮 DP
 * ��i�ֽ磬��ߵ������Ϊmaxpl[i]���ұߵ����Ϊmaxpr[i]
 * ��iλ�õ������Ϊmaxpl[i] + maxpr[i]����������i�������ֵ
 * maxpl[], �����ұ������
 * maxpr[], ���ҵ���������
 * Ϊ��ʡ�ռ䣬ֻ���maxpr[]��maxplֻ��һ���������棬�����ұ���ʱ����
 * ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
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