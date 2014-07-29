/***
 * 法1：二分法
 * 比较mid^2 和 x的大小，当x在mid^2, 和 (mid+1)^2 之间时，找到
 * 二分查找 返回下边界
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
 * 法2：牛顿迭代法求平方根
 * 先假设一猜测值X0 = 1，然后根据以下公式求出X1，再将X1代入公式右边，继续求出X2…通过有效次迭代后即可求出n的平方根，Xk+1
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