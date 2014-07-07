/***
 * 贪心法
 * 水深取决于两边较低的木板
 * 两个指针，左右夹逼，从最大长度开始
 * 每次收缩较小的一边
 * 扩展：若容器可以倾斜，最大蓄水量。
 * 这时蓄水的是一个梯形，上底height[low]，下底height[high]，高high-low
 ***/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxA = 0;
        int low = 0;
        int high = height.size() - 1;
        while (low < high)
        {
            int area = min(height[low], height[high]) * (high - low);
            maxA = max(maxA, area);
            
            if (height[low] < height[high])
                ++low;
            else
                --high;
        }
        return maxA;
    }
};