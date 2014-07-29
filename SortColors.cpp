/***
 * ��1�����α�������һ�μ������ڶ��θ�ֵ
 ***/
/*
class Solution {
public:
    void sortColors(int A[], int n) {
        vector<int> vcnt(3, 0);
        for (int i = 0; i < n; ++i)
            ++vcnt[A[i]];
        int i = 0;
        for (int j = 0; j < 3; ++j)
            while (vcnt[j]--)
                A[i++] = j;
        return;
    }
};
*/

/***
 * ��2��һ��������������ָ��red blue i
 * red ���0��λ�ã�blue�ұ�2��λ�ã�iѭ������
 * ��0��ǰ�ţ�2����ţ�1��Ȼ���м�
 ***/
class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0;
        int blue = n-1;
        int i = 0;
        while (i <= blue)
        {
            switch (A[i])
            {
                case 0:
                    swap(A[i++], A[red++]);
                    break;
                case 1:
                    ++i;
                    break;
                case 2:
                    swap(A[i], A[blue--]);
                    break;
            }
        }
        return;
    }
};