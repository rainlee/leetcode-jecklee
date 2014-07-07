/***
 * ̰�ķ����ͽ��߳�
 * prices[i] > prices[i-1], ��i-1�����i����
 * ���������������ۼӺ�
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