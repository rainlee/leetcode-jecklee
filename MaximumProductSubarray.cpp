/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         God Bless Me     BUG Free Forever
*/
/***
 * 贪心
 * 记录i之前的连续最大乘积maxp和最小乘积minp（负数的情况）
 * 如果a[i] > 0, 则用maxp乘，并更新minp
 * 如果a[i] = 0, 则maxp minp 都取1
 * 如果a[i] < 0, 则用minp乘，并更新maxp
 * 注意a[i] = 0，时res跟0比，而不是maxp(1)
 ***/
class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n < 1)
            return 0;
            
        int maxp = 1;
        int minp = 1;
        int res = A[0];
        for (int i = 0; i < n; ++i)
        {
            if (A[i] > 0)
            {
                maxp = max(maxp * A[i], A[i]);
                minp = min(minp * A[i], A[i]);
            }
            else if (A[i] < 0)
            {
                int tmp = maxp;
                maxp = max(minp * A[i], A[i]);
                minp = min(tmp * A[i], A[i]);
            }
            else  // 0
            {
                maxp = 1;
                minp = 1;
            }
            if (A[i])
                res = max(res, maxp);
            else
                res = max(res, A[i]);
        }
        return res;
    }
};