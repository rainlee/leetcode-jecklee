/***
 * ���η�
 * x^n = x^(n/2) * x^(n/2) * x(n%2)
 * ע��nΪ���������
 * ʱ�临�Ӷ�O(logn)
 * ʹ��n>>1 �ᳬʱ? 1.00000, -2147483648 (2^31)
 * -n�����������
 ***/
/*
class Solution {
public:
    double pow(double x, int n) {
        if (n < 0)
            return 1.0 / binpow(x, -(long long)n);
        else
            return binpow(x, n);
    }
private:
    //double binpow(double x, int n) {
    double binpow(double x, long long n) {
        if (0 == n)
            return 1;
        if (1 == n)
            return x;
        //double v = binpow(x, n/2);
        double v = binpow(x, n >> 1);
        return (n & 0x1) ? v*v*x : v*v;
    }
};
*/

/***
 * ��2������ ����
 * ͨ��ɨ��n�Ķ����Ʊ�ʾ��ʽ�ﲻͬλ���ϵ�1��������x���ݴ�
 * ����nȡֵINT_MINʱ��-n������INT_MAX����ʱ��Ҫ����С�ġ�
 * ����ʹ����λ����������������㣬�ӿ��㷨ִ�е��ٶȡ�
 ***/
class Solution {
public:
    double pow(double x, int n) {
        if (0 == n)
            return 1;
        long long lln = abs((long long)n);
        double ret = 1.0;
        while (lln)
        {
            if (lln & 0x1)
                ret *= x;
            lln >>= 1;
            x *= x;
        }
        return (n < 0) ? 1.0/ret : ret;
    }
};