/***
 * DP
 * dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
 * ����triangle���飬ÿ�θ��½ڵ�ֵ�������½�dp����
 * ������ܸı�ԭ���飬����Ҫ�½�dp[][]
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
 * ��2��DP
 * �ӵ����ϼ��㣬�߼����򵥣�ȥ���Һ��ӵĽ�Сֵ�������жϱ߽�
 * �������С·��ֵ��Ϊrootֵ�������ٱ������һ��
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