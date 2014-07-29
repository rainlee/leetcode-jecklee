/***
 * ��1��������ת������
 * ����������������λ��Ϊ����������λ��
 * ������θ�λΪ��������ĸ�λ��θ�λ�ֻ�
 * �Դ�����
 ***/
/*
class Solution {
public:
    vector<int> grayCode(int n) {
        const int size = 1 << n;  // 2^n
        vector<int> gray(size);
        for (int i = 0; i < size; ++i)
            gray[i] = i ^ (i >> 1);
        return gray;
    }
};
*/

/***
 * ��2���ݹ����ɸ�����
 * �������¹����������
 * 1λ���������������֣�(n+1)λ�������ܵݹ�Ĵ�nλ����������
 * (n+1)λ�������е�ǰ2^n�����ֵ���nλ����������֣���˳����д����ǰ׺0
 * (n+1)λ�������еĺ�2^n�����ֵ���nλ����������֣���������д����ǰ׺1
 ***/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray;
        gray.reserve(1 << n);   // caution: faster
        gray.push_back(0);
        for (int i = 0; i < n; ++i)
        {
            const int prefix = 1 << i;  // highest bit
            for (int j = gray.size() - 1; j >= 0; --j)  // reverse gray[0, n)
                gray.push_back(prefix | gray[j]);
        }
        return gray;
    }
};