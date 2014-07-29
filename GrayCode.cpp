/***
 * 法1：二进制转格雷码
 * 保留二进制码的最高位作为格雷码的最高位，
 * 格雷码次高位为二进制码的高位与次高位抑或
 * 以此类推
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
 * 法2：递归生成格雷码
 * 利用如下规则构造格雷码
 * 1位格雷码有两个码字，(n+1)位格雷码能递归的从n位格雷码生成
 * (n+1)位格雷码中的前2^n个码字等于n位格雷码的码字，按顺序书写，加前缀0
 * (n+1)位格雷码中的后2^n个码字等于n位格雷码的码字，按逆序书写，加前缀1
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