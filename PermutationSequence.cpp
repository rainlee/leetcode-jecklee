/***
 * ��1��DFS ������һֱ��k
 * �ⷽ���ᳬʱ
 * ��2����ѧ�������������� - Cantor���б���
 * n��������n!�����У���n��(n-1)!�����У����ŵ�һ����
 * �Ե�k�����У�ͨ����(n-1)!ȡ�࣬����֪��������n���еĵڼ���
 * ��Ϊ��i�飬����Ϊʣ��n-1����������
 * ���ŵ�һ��������i��ʣ�µ�n-1��������С��������
 * ���ƣ�n-1������n-1��(n-2)!������
 * ��ΪҪ�������Խ�������Ҫ��ʣ��Ԫ������ֻ��Ҫ�ѵ�ǰҪ�ŵ�Ԫ�ز��뵽ǰ��Ϳ����ˣ���
 ***/
/*
class Solution {
public:
    string getPermutation(int n, int k) {
        string sper;
        for (int i = 1; i <= n; ++i)  // init
            sper += char(i + '0');
        
        if (n <= 1)
            return sper;
        
        vector<int> fact(n);   // factorial power
        fact[0] = 1;
        for (int i = 1; i < n; ++i)
            fact[i] = fact[i-1] * i;
        
        k -= 1;   // index for 0 ~ n-1
        for (int i = 0; i < n; ++i)
        {
            int pos = k / fact[n-i-1];  // choose the item in (pos+i)
            k %= fact[n-i-1];           //  ... s[i] ... s[i+pos] ... s[n-1]
                                        //  ... s[i+pos] . s[i]. s[i+1] ... s[n-1]
            int tmp = sper[pos+i];
            for (int j = pos+i; j > i; --j)  // insert (tmp) forword in pos (i)
                sper[j] = sper[j-1];
            sper[i] = tmp;
            
            if (0 == k)  // neednt move
                break;
        }
        return sper;
    }
};
*/

/***
 * ��3��ͬ��2������������ʵ��
 * ���Գ�ʼ�ַ���sper����ǰ�壬���⽨һ������ַ���
 * ÿ�ΰѵ�ǰѡ����ַ���ӵ�����ַ��������Ҵ�sper��ɾ��
 * ���⣬�׳�Ҳ���ñ���0~n-1��ֻ����n-1�������Ŀ��Լ���������Ż��ռ�
 ***/
class Solution {
public:
    string getPermutation(int n, int k) {
        string sper;
        int fact = 1;
        for (int i = 1; i <= n; ++i)  // init
        {
            sper += char(i + '0');
            fact *= i;
        }
        
        if (n <= 1)
            return sper;
        
        string skper;
        --k;
        while (n)
        {
            fact /= n;   // calc factorial power
            int pos = k / fact;
            k %= fact;
            skper.push_back(sper[pos]);
            sper.erase(pos, 1);
            --n;
        }
        return skper;
    }
};