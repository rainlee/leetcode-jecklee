/***
 * 将Search in Rotated Sorted Array改进一下
 * A[mid] == A[low] 时 low++
 * 有可能退化为O(n)
 ***/
class Solution {
public:
    bool search(int A[], int n, int target) {
        if ((NULL == A) || (0 == n))
            return false;
        
        int low = 0;
        int high = n-1;
        
        while (low <= high)
        {
            int mid = low + (high-low)/2;
            
            if (target == A[mid])
                return true;
            
            if (A[mid] > A[low]) // low-mid are sorted
            {
                if ((target >= A[low]) && (target < A[mid]))
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if (A[mid] < A[low])
            {
                if ((target > A[mid]) && (target <= A[high]))
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
                ++low;   // A[low] != target
        }
        return false;
    }
};