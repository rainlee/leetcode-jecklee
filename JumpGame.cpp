/***
 * 法1：贪心
 * 每次都记录能够i位置能到达的最远距离，
 * 当到达n-1，或者不能继续前进时，停止
 ***/
/*
class Solution {
public:
    bool canJump(int A[], int n) {
        int maxrb = 0;  // max right bound
        for (int i = 0; i < n; ++i)
        {
            maxrb = max(maxrb, A[i]);  // can move maxrb steps
            if (maxrb > 0)  // move on
                --maxrb;
            else            // stop here
                return (i == n-1);     // if reach the end
        }
        return true;  // reach the end
    }
};
*/

/***
 * 法2：贪心
 * 从左往右遍历，记录从0开始能到达的最远位置
 * 如果能超过n-1，则可以到达
 ***/
/*
class Solution {
public:
    bool canJump(int A[], int n) {
        int maxrb = 0;
        for (int i = 0; (i <= maxrb) && (maxrb < n); ++i)  // i <= maxrb, can reach
            maxrb = max(maxrb, i + A[i]);
        return (maxrb >= n-1);
    }
};
*/

/***
 * 法3：贪心
 * 从右往左，检查能否跳回0
 ***/
class Solution {
public:
    bool canJump(int A[], int n) {
        int lb = n-1;  // left bound
        for (int i = n-2; i >= 0; --i)
            if (i + A[i] >= lb)
                lb = i;
        return (lb <= 0);
    }
};