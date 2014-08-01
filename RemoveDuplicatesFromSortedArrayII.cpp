/***
 * 两个指针，从前往后遍历
 * i遍历，j复制
 * 用cnt记录重复的次数，两次以上的不复制
 ***/
/*
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2)
            return n;
            
        int j = 0;
        int cnt = 1;   // at least one
        
        for (int i = 1; i < n; ++i)
        {
            if (A[i] != A[i-1])
            {
                A[++j] = A[i];
                cnt = 1;
            }
            else
            {
                if (++cnt <= 2)    // else dont copy
                    A[++j] = A[i];
            }
        }
        
        return (j+1);
    }
};
*/

/***
 * 法2：仍然使用双指针
 * 每次把当前字符和已复制的倒数第二个字符比较，不等则可以复制
 ***/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 3) 
            return n;
        int i = 2;
        for (int j = 2; j < n; ++j)
            if (A[j] != A[i-2])
                A[i++] = A[j];
        return i;
    }
};