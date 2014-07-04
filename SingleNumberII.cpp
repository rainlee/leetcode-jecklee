/***
 * 模拟三进制加法
 * ones 表示 第一位，0 1 0 1 变化
 * twos 表示 第二位，10 11 变化
 * threes 表示 第三位，1xx 0xx 变化
 ***/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0;
        int twos = 0;
        int threes = 0;
        
        for (int i = 0; i < n; ++i)
        {
            twos |= ones & A[i];
            ones ^= A[i];
            threes = ones & twos;
            
            ones &= ~threes;
            twos &= ~threes;
        }
        
        return ones;
    }
};