/***
 * ģ�������Ƽӷ�
 * ones ��ʾ ��һλ��0 1 0 1 �仯
 * twos ��ʾ �ڶ�λ��10 11 �仯
 * threes ��ʾ ����λ��1xx 0xx �仯
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