/***
 * 分治法
 * x^n = x^(n/2) * x^(n/2) * x(n%2)
 * 注意n为负数的情况
 * 时间复杂度O(logn)
 * 使用n>>1 会超时? 1.00000, -2147483648 (2^31)
 * -n会溢出！！！
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
 * 法2：二分 迭代
 * 通过扫描n的二进制表示形式里不同位置上的1，来计算x的幂次
 * 对于n取值INT_MIN时，-n并不是INT_MAX，这时需要格外小心。
 * 尽量使用移位运算来代替除法运算，加快算法执行的速度。
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