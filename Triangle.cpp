/***
 * DP
 * dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
 * 复用triangle数组，每次更新节点值，不用新建dp数组
 * 如果不能改变原数组，则需要新建dp[][]
 ***/
/*
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for (int i = 1; i < triangle.size(); ++i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                if (0 == j)
                    triangle[i][j] += triangle[i-1][j];
                else if (triangle[i].size()-1 == j)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        int minsum = INT_MAX;
        const int n = triangle.size();
        const int m = triangle[n-1].size();
        for (int j = 0; j < m; ++j)
            minsum = min(minsum, triangle[n-1][j]);
        return minsum;
    }
};
*/

/***
 * 法2：DP
 * 从底至上计算，逻辑更简单，去左右孩子的较小值，不用判断边界
 * 且最后最小路径值即为root值，不用再遍历最后一行
 * triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])
 ***/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for (int i = triangle.size()-2; i >= 0; --i)
            for (int j = 0; j < triangle[i].size(); ++j)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        return triangle[0][0];
    }
};