/***
 * ��A[i] !=  i+1ʱ����A[i]�û�����Ӧ���ڵ�λ��A[A[i]-1]
 * ����һ�� �û�����֮�� �ټ���һ����ƥ�����
 ***/
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while (i < n)
        {
            if ((A[i] != i+1) && (A[i] > 0) && (A[i] < n) && (A[A[i]-1] != A[i]))
                swap(A[i], A[A[i]-1]);
            else
                ++i;
        }
        for (i = 0; i < n; ++i)
            if (A[i] != i+1)
                return i+1;
        return n+1;
    }
};