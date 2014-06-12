/***
 * ��1��������merge����ʱ�临�Ӷ�O(n+m)
 * ע��m+nΪż��ʱ����λ�����м�����ƽ��
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
 * ��2��O(logn)
 * ��Ѱ��ÿ���������λ����O(1)
 * Ȼ�󣬱Ƚ����������ֵĴ�С��
 * ���A����λ������B����λ��������A��ǰ��������B�ĺ���������Ѱ��; 
 * ��֮����B��ǰ��������A�ĺ�������Ѱ�ҡ�
 * m+n Ϊ����ʱ��Ѱ��(m+n+1)/2
 * Ϊż��ʱ��Ϊ(m+n)/2��(m+n)/2 + 1 �м�����֮��
 * ��Ѱ����λ��ת��ΪѰ�ҵ�k�����
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