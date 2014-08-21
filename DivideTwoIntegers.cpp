/***
 * ��1��ѭ�������O(n) Ԥ�ƻᳬʱ
 * ��2�����ַ�
 * ÿ��ȡ�е㣬�Ƚ�dividend �� divisor * mid
 *  > , high = mid - 1
 *  = , return
 *  < , low = mid + 1, ���������ս������������ʱ��
 * ȡ�е��������λ��������˷������ö��ּ���λ��
 * ����ע�⴦�����Ϊ�������͸���
 * ����������ͳһתΪ��������Ϊ�˱��⸺��ת�������������long long
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
 * ��3��ÿ�ν�����������1����ͬʱ��countҲ����һ������������˱���������ô�ñ�������ȥ��ǰ���ټ�����������
 * ÿ������̵����λ��Ȼ��θ�λ��ֱ�����
 * ���� 12 / 2��2 * 2^2 < 12���̵����λ��2^2������12 - 2 * 2^2 = 4
 * 2 * 2^1 = 4���̵Ĵθ�λ��2^1������0
 * �� 2^2 + 2^1 = 6
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