/***
 * DP
 * dp[i]记录能达到i的最小步数，每次如果能访问到i则更新dp[i]
 * 时间复杂度O(n) 空间复杂度O(n)
 ***/
/*
class Solution {
public:
    int jump(int A[], int n) {
        if (0 == n)
            return 0;
            
        vector<int> dp(n, INT_MAX);
        int maxrb = 0;
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            int reach = i + A[i];
            if (reach <= maxrb)    // cant be smaller, without this, timeout
                continue;
                
            maxrb = reach;
            for (int j = i+1; (j <= maxrb) && (j < n); ++j)
                dp[j] = min(dp[j], dp[i] + 1);
        }
        if (maxrb < n-1)  // cant reach
            return -1;
        else
            return dp[n-1];
    }
};
*/

/***
 * 法2：贪心
 * 计算每一步能达到的范围，一步步跳，直到到达n-1
 * [left, right]维护当前一跳能达到的空间
 * 时间复杂度O(n) 空间复杂度O(1)
 ***/
/*
class Solution {
public:
    int jump(int A[], int n) {
        if (n < 2)
            return 0;
        
        int step = 0;
        int left = 0;
        int right = 0;
        
        while (left <= right)
        {
            ++step;
            int old_right = right;
            while (left <= old_right)
            {
                int new_right = left + A[left];
                if (new_right >= n-1)     // reach the end
                    return step;
                
                right = max(right, new_right);
                ++left;
            } // left = old_right + 1
        }
        return -1;  // cant reach
    }
};
*/

/***
 * 法3：贪心
 * 记录当前能达到的最右边界 和 下一步能到达的最右边界
 * 当前不能到达时，则进行下一步，并更新能到达的最右边界
 ***/
class Solution {
public:
    int jump(int A[], int n) {
        int currb = 0;   // cur step right bound
        int nextrb = 0;  // next step right bound, max right bound
        int step = 0;
        for (int i = 0; i < n; ++i)
        {
            if (currb < i)  // cant reach
            {
                ++step;
                currb = nextrb;
            }
            nextrb = max(nextrb, i + A[i]);
        }
        return step;
    }
};
