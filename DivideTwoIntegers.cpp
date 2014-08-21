/***
 * 法1：循环相减，O(n) 预计会超时
 * 法2：二分法
 * 每次取中点，比较dividend 和 divisor * mid
 *  > , high = mid - 1
 *  = , return
 *  < , low = mid + 1, 可能是最终结果（不能整除时）
 * 取中点可以用移位操作，求乘法可以用二分加移位。
 * 另外注意处理除数为零的情况和负数
 * 除数被除数统一转为正数处理，为了避免负数转成正数溢出，用long long
 ***/
/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);   // divisor cant be zero
        bool bneg = ((dividend > 0) && (divisor < 0) || 
                     (dividend < 0) && (divisor > 0));
        
        long long lldividend = abs((long long)dividend);  // cast here
        long long lldivisor = abs((long long)divisor);
        long long low = 0;
        long long high = lldividend;
        long long mid = -1;
        long long ret = -1;
        while (low <= high)
        {
            mid = (low&high) + ((low^high) >> 1);
            long long llmul = mul(lldivisor, mid);
            if (llmul == lldividend)
            {
                ret = mid;
                break;
            }
            else if (llmul > lldividend)
                high = mid - 1;
            else
            {
                ret = mid;      // maybe the answer
                low = mid + 1;
            }
        }
        return bneg ? -ret : ret;
    }
private:
    long long mul(long long a, long long b)
    {
        if (a < b)
            return mul(b, a);
        if (b == 0)
            return 0;
        if (b == 1)
            return a;
        long long tmp = mul(a, b >> 1) << 1;   // binary
        return (b & 0x1) ? (tmp + a) : tmp;
    }
};
*/

/***
 * 法3：每次将被除数增加1倍，同时将count也增加一倍，如果超过了被除数，那么用被除数减去当前和再继续本操作。
 * 每次求出商的最高位，然后次高位，直到最后
 * 比如 12 / 2，2 * 2^2 < 12，商的最高位是2^2，余数12 - 2 * 2^2 = 4
 * 2 * 2^1 = 4，商的次高位是2^1，余数0
 * 商 2^2 + 2^1 = 6
 ***/
class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);   // divisor cant be zero
        bool bneg = ((dividend > 0) && (divisor < 0) || 
                     (dividend < 0) && (divisor > 0));
        
        long long lldividend = abs((long long)dividend);  // cast here
        long long lldivisor = abs((long long)divisor);
        long long ret = 0;
        while (lldividend >= lldivisor)
        {
            long long div = lldivisor;
            long long digit = 1;
            while ((div << 1) <= lldividend)
            {
                div <<= 1;    // double the divisor
                digit <<= 1;
            }
            lldividend -= div;  // remainder
            //ret += digit;
            ret |= digit;
        }
        return bneg ? -ret : ret;
    }
};