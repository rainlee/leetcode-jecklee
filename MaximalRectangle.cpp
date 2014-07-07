/***
 * 动态规划，每次处理一行
 * 用dp[i][j] 表示(i,j)作为矩阵右下角，往上纵向y轴上的连续1的个数
 *            / 0, if matrix[i][j] == '0'
 * dp[i][j] = - 1, if matrix[i][j] == '1' && i == 0
 *            \ dp[i-1][j] + 1, else
 * 然后再横向x轴转化为Largest Rectangle in Histogram
 * 从j往前计算，直到matrix[i][k] = 0
 * 同理，可以每次处理一列
 * 时间复杂度O(n^3)
 ***/
/*
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) 
            return 0;
            
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        int maxR = 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ('0' == matrix[i][j])
                    continue;
                
                dp[i][j] = (i == 0) ? 1 : (dp[i-1][j] + 1);  // cal dp
                
                int minh = dp[i][j];
                for (int k = j; k >= 0; --k)  // form j to 0
                {
                    minh = min(minh, dp[i][k]);
                    maxR = max(maxR, (j-k+1) * minh);
                }
            }
        }
        return maxR;
    }
};
*/

/***
 * 法2：同样是每次算一行
 * 区别于法1，法1是每次算出一个dp[i][j]，就横向往前算一个maxR
 * 可以一次先算出一行的dp[i][j]，然后对这一行使用Largest Rectangle in Histogram
 * 为简化空间，可直接用一维的dp[j]表示，上一行dp[i-1][j]就是dp[j]的上一个值
 * 直方图的最大矩形可以用栈在O(n)时间中求出
 * 整个算法的时间复杂度O(n^2)
 ***/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) 
            return 0;
            
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        int maxR = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i)
        {
            // cal dp[] of a row
            for (int j = 0; j < n; ++j)
                dp[j] = ('0' == matrix[i][j]) ? 0 : (dp[j] + 1);  // old dp[j] is the value of last row
            
            // cal "Largest Rectangle in Histogram"
            maxR = max(maxR, largestRectangleArea(dp));
        }
        return maxR;
    }
private:
    int largestRectangleArea(vector<int> &height)
    {
        int maxRA = 0;
        height.push_back(0);
        stack<int> s;
        
        for (int i = 0; i < height.size();)
        {
            if (s.empty() || (height[i] >= height[s.top()]))
                s.push(i++);
            else
            {
                int minh = height[s.top()];
                s.pop();
                int width = s.empty() ? i : (i - s.top() - 1);
                maxRA = max(maxRA, width * minh);
            }
        }
        return maxRA;
    }
};