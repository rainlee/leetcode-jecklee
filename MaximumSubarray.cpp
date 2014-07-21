/***
 * 贪心
 * 从左往右累加，当累加值为负丢弃之前的sum值
 * 遍历过程中记录最大和
 * 时间复杂度O(n)
 ***/
/*
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
        int maxs = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            if (sum <= 0)
                sum = A[i];
            else
                sum += A[i];
            maxs = max(maxs, sum);
        }
        return maxs;
    }
};
*/

/***
 * 法2：divide and conquer 二分递归
 * 最大子序列可能在三个地方出现，或者在左半部，或者在右半部，或者跨越输入数据的中部而占据左右两部分。
 * 前两种情况递归求解，第三种情况的最大和可以通过求出前半部分最大和（包含前半部分最后一个元素）以及
 * 后半部分最大和（包含后半部分的第一个元素）相加而得到。
 * 时间复杂度O(n*logn)
 ***/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        return maxSubArrayRec(A, 0, n-1);
    }
private:
    int maxSubArrayRec(int A[], int low, int high)
    {
        if (low == high)
            //return (A[low] > 0) ? A[low] : 0;
            return A[low];  // maybe minus
        
        int mid = (low&high) + ((low^high) >> 1);
        int maxl = maxSubArrayRec(A, low, mid);
        int maxr = maxSubArrayRec(A, mid+1, high);
        
        int suml = 0;
        int maxsl = INT_MIN;
        for (int i = mid; i >= low; --i)  // max sum in [low, mid], including A[mid]
        {
            suml += A[i];
            maxsl = max(maxsl, suml);
        }
        
        int sumr = 0;
        int maxsr = INT_MIN;
        for (int i = mid+1; i <= high; ++i)  // max sum in (mid, high], including A[mid+1]
        {
            sumr += A[i];
            maxsr = max(maxsr, sumr);
        }
        
        return max(max(maxl, maxr), maxsl + maxsr);
    }
};