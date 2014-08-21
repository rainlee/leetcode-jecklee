/***
 * ��ǰ���������������
 * ����򲻸���
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
 * ��2��˫ָ�� �б�
 * lowָ���һ������elem��Ԫ�أ�highָ���һ��������elem��Ԫ��
 * Ȼ�����߽�������Ŀ��Ҫ�󱣳�ԭ˳��
 * ��ȷ�1 �����˸��ƴ��������븴���˺ܶ࡭����
 * ע�⣺������ʱlow==high���ܶ�ָ��elem
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