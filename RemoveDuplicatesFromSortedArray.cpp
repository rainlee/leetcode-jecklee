/***
 * 快慢指针
 * 两个指针从前往后遍历
 * 快指针指向原数组，慢指针指向新数组
 * 当重复时，慢指针不动，快指针继续往后遍历
 ***/
/*
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2)
            return n;
            
        int i = 1;
        int j = 1;
        
        while (i < n)
        {
            if (A[i] == A[i-1])
                i++;
            else
            {
                A[j] = A[i];
                i++;
                j++;
            }
        }
        return j;
    }
};
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2)
            return n;
        
        int i = 0;
        int j = 0;
        
        while (++i < n)
            if (A[i] != A[i-1])
                A[++j] = A[i];
        
        return (j+1);
    }
};