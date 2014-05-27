/***
 * ����ָ�룬��ǰ�������
 * i������j����
 * ��cnt��¼�ظ��Ĵ������������ϵĲ�����
 ***/
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