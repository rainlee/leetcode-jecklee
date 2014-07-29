/***
 * 法1：先排序，后计数，时间复杂度O(nlogn)
 * 法2：空间换取时间，构造hash表，只需保存key，不需要计数（重复元素只记一次就可以了）
 *      从第一个数开始，找前面和后面的数，两边加起来就是这个数得到的最大长度；向后遍历，更新最大值
 *      优化：找过的数可以删掉（否则后面会重复查找，因为该连续段的数都被访问过）
 ***/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> smap;
        for (int i = 0; i < num.size(); ++i)  // create hash map
            smap.insert(num[i]);
        
        int maxl = INT_MIN;
        for (int i = 0; (i < num.size()) && !smap.empty(); ++i)
        {
            int maxi = 1;  // max len, expend (i)
            
            int left = num[i];
            while (smap.find(--left) != smap.end())  // expend to left
            {
                smap.erase(left);  // erase visited node
                ++maxi;
            }
            int right = num[i];
            while (smap.find(++right) != smap.end())
            {
                smap.erase(right);
                ++maxi;
            }
            maxl = max(maxl, maxi);
        }
        return maxl;
    }
};