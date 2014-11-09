/***
 * 二分查找 O(logn)
 * 通过比较num[mid] num[low]判断左右两部分，哪一部分是有序的
 * 有序部分的最小值可能是全局的最小值
 * 然后再查找另外一部分
 ***/
class Solution {
public:
    int findMin(vector<int> &num) {
        const int n = num.size();
        if (n == 0) return INT_MAX;
        if (n == 1) return num[0];
        if (num[0] < num[n-1]) return num[0];
        
        int low = 0;
        int high = n-1;
        int minv = num[0];
        while (low < high)
        {
            int mid = (low&high) + ((low^high) >> 1);
            if (num[mid] > num[mid+1])
                return min(minv, num[mid+1]);
            else if (num[mid] > num[low])
            {
                minv = min(minv, num[low]);
                low = mid + 1;
            }
            else if (num[mid] < num[low])
            {
                minv = min(minv, num[mid]);
                high = mid - 1;
            }
            else
            {
                minv = min(minv, num[low]);
                ++low;
            }
        }
        return min(minv, num[low]);
    }
};