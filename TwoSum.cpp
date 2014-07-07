/***
 * 法1：先排序（保存原来的索位置）
 * 然后用两个指针从两边往中间遍历
 * 若两者之和 sum > target，则--high
 * 若sum < target, ++low
 * 时间复杂度O(nlogn)
 ***/
/*
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> vret(2, 0);
        const int n = numbers.size();
        if (0 == n)
            return vret;
        
        vector<pair<int, int> > vnums(n);  // (num, index)
        for (int i = 0; i < n; ++i)
            vnums[i] = make_pair(numbers[i], i+1);
        
        sort(vnums.begin(), vnums.end(), pcmp);   // sort
        
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            int sum = vnums[low].first + vnums[high].first;
            if (sum == target)
                break;
            else if (sum > target)
                --high;
            else
                ++low;
        }
        vret[0] = std::min(vnums[low].second, vnums[high].second);
        vret[1] = std::max(vnums[low].second, vnums[high].second);
        
        return vret;
    }
private:
    static bool pcmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return (a.first < b.first);
    }
};
*/

/***
 * 哈希
 * 存储每数对应的下标（数相同的时候有bug？8 = 4+4）
 * 时间复杂度O(n) 空间复杂度O(n)
 * map不能存相同的数，每次都存的相同数的最后一个
 * 如果是8=4+4，找到的是第二个，不会出错……
 ***/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> vret(2, 0);
        const int n = numbers.size();
        if (0 == n)
            return vret;
            
        unordered_map<int, int> mnums;
        for (int i = 0; i < n; ++i)
            mnums[numbers[i]] = i + 1;
        
        for (int i = 0; i < n; ++i)
        {
            int dif = target - numbers[i];
            if ((mnums.find(dif) != mnums.end()) && (mnums[dif] != i+1)) // found
            {
                vret[0] = i + 1;
                vret[1] = mnums[dif];
                break;
            }
        }
        return vret;
    }
};