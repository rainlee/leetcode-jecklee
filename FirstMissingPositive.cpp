/***
 * 当A[i] !=  i+1时，将A[i]置换到它应该在的位置A[A[i]-1]
 * 遍历一遍 置换完了之后 再检查第一个不匹配的数
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