/***
 * DP
 * dp[i]��¼�ܴﵽi����С������ÿ������ܷ��ʵ�i�����dp[i]
 * ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(n)
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
 * ��2��̰��
 * ����ÿһ���ܴﵽ�ķ�Χ��һ��������ֱ������n-1
 * [left, right]ά����ǰһ���ܴﵽ�Ŀռ�
 * ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
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
 * ��3��̰��
 * ��¼��ǰ�ܴﵽ�����ұ߽� �� ��һ���ܵ�������ұ߽�
 * ��ǰ���ܵ���ʱ���������һ�����������ܵ�������ұ߽�
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
