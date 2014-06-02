/***
 * 类似二分查找
 * 先判断分界点在前半部分 还是后半部分，然后在相应部分查找
 * 若A[mid] >= A[low], 则前半部分有序；若A[low] <= target < A[mid]
 * 则在前半部分查找；否则在后半部分查找
 * 若A[mid] < A[high], 则后半部分有序；若A[mid] < target <= A[high]
 * 则在后半部分查找；否则在前半部分查找
 ***/
class Solution {
public:
    int search(int A[], int n, int target) {
        if ((NULL == A) || (0 == n))
            return -1;
        
        int low = 0;
        int high = n-1;
        
        while (low <= high)
        {
            int mid = low + (high-low)/2;
            
            if (target == A[mid])
                return mid;
            
            if (A[mid] >= A[low])
            {
                if ((target >= A[low]) && (target < A[mid]))
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if ((target >= A[mid]) && (target <= A[high]))
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};