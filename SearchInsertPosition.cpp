/***
 * ���ֲ��� lower_bound()
 * �ҵ������أ�û�ҵ������±߽�
 ***/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0;
        int high = n-1;
        while (low <= high)
        {
            int mid = (low & high) + ((low ^ high) >> 1);
            if (target == A[mid])
                return mid;
            else if (target > A[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};