/***
 * ̰��
 * ���������ۼӣ����ۼ�ֵΪ������֮ǰ��sumֵ
 * ���������м�¼����
 * ʱ�临�Ӷ�O(n)
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
 * ��2��divide and conquer ���ֵݹ�
 * ��������п����������ط����֣���������벿���������Ұ벿�����߿�Խ�������ݵ��в���ռ�����������֡�
 * ǰ��������ݹ���⣬��������������Ϳ���ͨ�����ǰ�벿�����ͣ�����ǰ�벿�����һ��Ԫ�أ��Լ�
 * ��벿�����ͣ�������벿�ֵĵ�һ��Ԫ�أ���Ӷ��õ���
 * ʱ�临�Ӷ�O(n*logn)
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