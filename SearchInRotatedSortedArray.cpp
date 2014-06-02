/***
 * ���ƶ��ֲ���
 * ���жϷֽ����ǰ�벿�� ���Ǻ�벿�֣�Ȼ������Ӧ���ֲ���
 * ��A[mid] >= A[low], ��ǰ�벿��������A[low] <= target < A[mid]
 * ����ǰ�벿�ֲ��ң������ں�벿�ֲ���
 * ��A[mid] < A[high], ���벿��������A[mid] < target <= A[high]
 * ���ں�벿�ֲ��ң�������ǰ�벿�ֲ���
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