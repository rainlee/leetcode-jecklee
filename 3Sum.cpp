/***
 * 先排序，然后取一个数，对剩下的数使用TwoSum
 * 可以推广到k-sum，先排序，然后做k-2次循环，在最内层使用2Sum
 * O(nlogn + n^2) = O(n^2)
 * 注意去重：
 * 外层循环，已经处理过的相同数字不再处理
 * 内存循环，找到一组后，与该组重复的不再处理
 * 另外一种是处理完之后再去重，使用unique库函数
 ***/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        const int n = num.size();
        if (0 == n)
            return vvsums;
        
        sort(num.begin(), num.end());   // sort first!
        
        for (int i = 0; i < n; ++i)
        {
            if ((i > 0) && (num[i] == num[i-1]))
                continue;
            twoSum(num, i+1, -num[i]);   
        }
        
        //sort(vvsums.begin(), vvsums.end());
        //vvsums.erase(unique(vvsums.begin(), vvsums.end()), vvsums.end());  // erase the dups
        
        return vvsums;
    }
private:
    vector<vector<int> > vvsums;
    
    void twoSum(vector<int> &num, int start, int target)
    {
        vector<int> vret(3);
        vret[0] = -target;
        
        int low = start;
        int high = num.size() - 1;
        
        while (low < high)
        {
            int sum = num[low] + num[high];
            if (sum == target)
            {
                vret[1] = num[low];
                vret[2] = num[high];
                vvsums.push_back(vret);
                
                //++low;
                //--high;
                
                while ((num[++low] == num[low-1]) && (low < high)) ;   // remove dups
                while ((num[--high] == num[high+1]) && (low < high));
            }
            else if (sum > target)
                --high;
            else
                ++low;
        }
        return;
    }
};