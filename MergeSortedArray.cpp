    /***
 * 为了避免使用多余的空间，从后往前merge，取大的
 ***/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        
        int i = m-1;
        int j = n-1;
        
        for (int k = (m+n-1); k >= 0; --k)
        {
            if (((i >=0) && (j >= 0) && (A[i] > B[j])) || (j < 0) )
                A[k] = A[i--];
            else
                A[k] = B[j--];
        }
        return;
    }
};