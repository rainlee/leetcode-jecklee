/***
 * 法1：两数组merge排序，时间复杂度O(n+m)
 * 注意m+n为偶数时，中位数是中间两数平均
 ***/
/*
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        
        int mid = (m+n+1) / 2;
        int i = 0;
        int j = 0;
        
        // merge
        int first = 0;
        while (mid--)
        {
            if (((i < m) && (j < n) && (A[i] <= B[j])) || (j >= n))
                first = A[i++];
            else
                first = B[j++];
        }
        
        double median;
        if ((m+n) % 2)
            median = first;
        else // get (mid+1)
        {
            int second = 0;
            
            if (((i < m) && (j < n) && (A[i] <= B[j])) || (j >= n))
                second = A[i];
            else
                second = B[j];
            
            median = (double)(first + second) / 2;
        }
        
        return median;
    }
};
*/

/***
 * 法2：O(logn)
 * 先寻找每个数组的中位数，O(1)
 * 然后，比较这两个数字的大小。
 * 如果A的中位数大于B的中位数，则在A的前半个数组和B的后半个数组中寻找; 
 * 反之，在B的前半个数组和A的后半个数组寻找。
 * m+n 为奇数时，寻找(m+n+1)/2
 * 为偶数时，为(m+n)/2，(m+n)/2 + 1 中间两数之和
 * 将寻找中位数转化为寻找第k大的数
 ***/
class Solution {
public:
    int findKthSortedArrays(int A[], int m, int B[], int n, int k)
    {
        if (m > n)
            return findKthSortedArrays(B, n, A, m, k);
        if (0 == m)
            return B[k-1];
        if (1 == k)
            return min(A[0], B[0]);
        
        int ia = min(k/2, m);
        int ib = k - ia;
        
        if (A[ia-1] < B[ib-1])       // remove A[0...ia-1] B[ib...n]
            return findKthSortedArrays(A+ia, m-ia, B, ib, k - ia);
            //return findKthSortedArrays(A+ia, m-ia, B, n, k - ia);
        else if (A[ia-1] > B[ib-1])  // remove A[ia...m] B[0...ib-1]
            return findKthSortedArrays(A, m, B+ib, n-ib, k - ib);
        else
            return A[ia-1];
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 0x01)
            return findKthSortedArrays(A, m, B, n, total/2 + 1);
        else
            return (findKthSortedArrays(A, m, B, n, total/2) + findKthSortedArrays(A, m, B, n, total/2 + 1)) / 2.0;
    }
};