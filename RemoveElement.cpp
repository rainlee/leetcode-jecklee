/***
 * 从前往后遍历，并复制
 * 相等则不复制
 ***/
/*
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int len = 0;
        for (int i = 0; i < n; ++i)
            if (A[i] != elem)
                A[len++] = A[i];
        return len;
    }
};
*/

/***
 * 法2：双指针 夹逼
 * low指向第一个等于elem的元素，high指向第一个不等于elem的元素
 * 然后两者交换（题目不要求保持原顺序）
 * 相比法1 减少了复制次数（代码复杂了很多……）
 * 注意：最后结束时low==high可能都指向elem
 ***/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (0 == n)
            return 0;
        int low = 0;
        int high = n-1;
        while (low < high)
        {
            while ((low < high) && (A[low] != elem))
                ++low;
            while ((low < high) && (A[high] == elem))
                --high;
            if (low < high)
                swap(A[low], A[high]);
        }
        if (A[low] == elem)
            return low;
        else
            return low+1;
    }
};