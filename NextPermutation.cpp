/***
 * �����⺯��pre_permutation next_permutation, ����ֵbool
 * ���Ͽ⺯��ԭ��
 * next_permutation ǰ��С�ĺͺ������û�
 * ��Χ��[first,last)��ǣ����ݱ�ǴӺ���ǰ�Ƚ����������ݣ�
 * ��ǰ��С�ڣ�Ĭ��ΪС�ڣ����ߣ���־ǰ��ΪX1��λ��PX����ʾ�����滻��
 * �ٴδӺ���ǰ������һ������X1�����ݣ����ΪX2������X1��X2���������ڵ�һ�α���ʱ��¼��
 * Ȼ���[PX+1��last)��Ƿ�Χ���档
 * Ҫ�㣺Ϊʲô�����Ϳ��Ա�֤�õ���Ϊ��С������
 * ��λ��first��ʼԭ�����������в�ͬ������λ����PX������������ΪX2��[PX+1��last)���ǵݼ��ģ�[first,PX)û�иı䣬
 * ��ΪX2>X1,���Բ���X2�����������ж���ԭ���д󣬷�ת[PX+1��last)ʹ��������(����)Ϊ��С��
 * �Ӷ���֤��������Ϊԭ���е��ֵ�������next��
 * 
 * ���Ƶ�˼�������pre_permutation ǰ���ĺͺ���С���û�
 * �Ӻ���ǰ�������ҵ���һ�����ڵ�X1>X2��X1�����滻���Ѵ�������ƣ�
 * �ٴδӺ���ǰ�������ҵ���һ��С��X1������X3������X1 X3
 * Ȼ���[X2 last) ���ã�ʹ�������еݼ���
 ***/
/*
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int x1 = -1;
        int x2 = -1;
        
        for (int i = num.size()-2; i >= 0; --i)
        {
            if (num[i] < num[i+1])
            {
                x1 = i;
                break;
            }
        }
        
        if (x1 >= 0)
        {
            for (int i = num.size()-1; i > x1; --i)
            {
                if (num[i] > num[x1])
                {
                    x2 = i;
                    break;
                }
            }
            swap(num[x1], num[x2]);
        }
        sort(num.begin() + x1 + 1, num.end());  // including x1 = 0, reverse the reset array
        return;
    }
};
*/

/***
 * ��2��һ�ָ����Ĵ���
 ***/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size() - 1;
        while ((i > 0) && (num[i] <= num[i-1]))
            --i;
        reverse(num.begin() + i, num.end());  // reverse [i, n-1]
        if (0 == i)
            return;
        
        int j = i;
        while ((j < num.size()) && (num[j] <= num[i-1]))
            ++j;
        swap(num[i-1], num[j]);
        return;
    }
};