/***
 * ��̬�滮��ÿ�δ���һ��
 * ��dp[i][j] ��ʾ(i,j)��Ϊ�������½ǣ���������y���ϵ�����1�ĸ���
 *            / 0, if matrix[i][j] == '0'
 * dp[i][j] = - 1, if matrix[i][j] == '1' && i == 0
 *            \ dp[i-1][j] + 1, else
 * Ȼ���ٺ���x��ת��ΪLargest Rectangle in Histogram
 * ��j��ǰ���㣬ֱ��matrix[i][k] = 0
 * ͬ������ÿ�δ���һ��
 * ʱ�临�Ӷ�O(n^3)
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
 * ��2��ͬ����ÿ����һ��
 * �����ڷ�1����1��ÿ�����һ��dp[i][j]���ͺ�����ǰ��һ��maxR
 * ����һ�������һ�е�dp[i][j]��Ȼ�����һ��ʹ��Largest Rectangle in Histogram
 * Ϊ�򻯿ռ䣬��ֱ����һά��dp[j]��ʾ����һ��dp[i-1][j]����dp[j]����һ��ֵ
 * ֱ��ͼ�������ο�����ջ��O(n)ʱ�������
 * �����㷨��ʱ�临�Ӷ�O(n^2)
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