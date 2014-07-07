/***
 * ͬ3Sum���������Ҽб�2Sum
 * ֻ�����ж���������ͬ ��Ϊ���ӽ�target������ֵ��
 * ���ǳ������չ�ԣ����Ը�2Sum��һ���жϵĺ���ָ��
 * �������뱣ֻ֤��һ���⣬���ÿ�ȥ��
 * ʱ�临�Ӷ�O(n^2)
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