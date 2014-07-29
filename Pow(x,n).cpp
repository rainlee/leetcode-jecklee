/***
 * ���η�
 * x^n = x^(n/2) * x^(n/2) * x(n%2)
 * ע��nΪ���������
 * ʱ�临�Ӷ�O(logn)
 * ʹ��n>>1 �ᳬʱ? 1.00000, -2147483648
 ***/
class Solution {
public:
    double pow(double x, int n) {
        if (n < 0)
            return 1.0 / binpow(x, -n);
        else
            return binpow(x, n);
    }
private:
    double binpow(double x, int n) {
        if (0 == n)
            return 1;
        if (1 == n)
            return x;
        double v = binpow(x, n/2);
        //double v = binpow(x, n >> 1);
        return (n & 0x1) ? v*v*x : v*v;
    }
};