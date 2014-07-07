/***
 * 先排序，后左右夹逼
 * 三层循环，可以直接调用3Sum
 * 时间复杂度O(n^3)
 * 注意去重
 ***/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        const int n = num.size();
        
        std::sort(num.begin(), num.end());  // sort first!!!
        
        for (int i = 0; i < n-3; ++i)
        {
            if ((i > 0) && (num[i] == num[i-1]))
                continue;
            threeSum(num, i, target);
        }
        return vvnums;
    }
private:
    vector<vector<int> > vvnums;
    
    void twoSum(vector<int> &num, int i1, int i2, int target)
    {
        vector<int> vret(4);
        vret[0] = num[i1];
        vret[1] = num[i2];
        
        int low = i2 + 1;
        int high = num.size() - 1;
        
        while (low < high)
        {
            int sum = num[i1] + num[i2] + num[low] + num[high];
            
            if (sum == target)
            {
                vret[2] = num[low];
                vret[3] = num[high];
                
                vvnums.push_back(vret);
                
                while ((num[++low] == num[low-1]) && (low < high)) ;
                while ((num[--high] == num[high+1] && (low < high)));
            }
            else if (sum > target)
                --high;
            else
                ++low;
        }
        return;
    }
    void threeSum(vector<int> &num, int i1, int target)
    {
        for (int i = i1+1; i < num.size()-2; ++i)
        {
            if ((i > i1+1) && (num[i] == num[i-1]))
                continue;
            twoSum(num, i1, i, target);
        }
        return;
    }
};