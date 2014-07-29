/***
 * ��1�����ַ�
 * �Ƚ�mid^2 �� x�Ĵ�С����x��mid^2, �� (mid+1)^2 ֮��ʱ���ҵ�
 * ���ֲ��� �����±߽�
 ***/
/*
class Solution {
public:
    int sqrt(int x) {
        if (x < 2)
            return x;
            
        int low = 0;
        int high = x/2 + 1;
        while (low <= high)
        {
            int mid = (low & high) + ((low ^ high) >> 1);
            int half = x / mid;  // avoid overflow
            if (half == mid)
                return mid;
            else if (half > mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;  // lower bound
    }
};
*/

/***
 * ��2��ţ�ٵ�������ƽ����
 * �ȼ���һ�²�ֵX0 = 1��Ȼ��������¹�ʽ���X1���ٽ�X1���빫ʽ�ұߣ��������X2��ͨ����Ч�ε����󼴿����n��ƽ������Xk+1
 * x(k+1) = (x(k) + n/x(k)) / 2;
 ***/
class Solution {
public:
    int sqrt(int x) {
        if (x < 2)
            return x;
        double ret = 1;
        while (abs(ret*ret - x) > 0.1)
            ret = (ret + x / ret) / 2;
        return ret;
    }
};