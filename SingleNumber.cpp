/***
 * 逐位抑或 最后结果即为所求
 * 不仅能处理两次的情况，只要出现偶数次，都可以清零。
 ***/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int num = 0;
        for (int i = 0; i < n; ++i)
            num ^= A[i];
        return num;
    }
};