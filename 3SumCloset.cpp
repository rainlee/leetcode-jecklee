/***
 * 同3Sum，排序，左右夹逼2Sum
 * 只不过判断条件由相同 变为更接近target（绝对值）
 * 考虑程序的扩展性，可以给2Sum传一个判断的函数指针
 * 由于输入保证只有一个解，不用考去重
 * 时间复杂度O(n^2)
 ***/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        
        std::sort(num.begin(), num.end());
        
        closet = num[0] + num[1] + num[2];
        
        for (int i = 0; i < num.size()-2; ++i)
        {
            if ((i > 0) && (num[i] == num[i-1]))
                continue;
            if (target == twoSum(num, i+1, num[i], target))
                break;
        }
        return closet;
    }
private:
    int closet;
    int twoSum(vector<int> &num, int start, int num1, int target)
    {
        int low = start;
        int high = num.size() - 1;
        
        while (low < high)
        {
            int sum = num1 + num[low] + num[high];
            
            closet = (abs(sum - target) < abs(closet - target)) ? sum : closet;
            
            if (sum == target)  // equal found
                break;
            else if (sum > target)
                --high;
            else
                ++low;
        }
        return closet;
    }
};