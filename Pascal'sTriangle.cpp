/***
 * 递推公式 DP
 * triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
 * 两边的值为1
 ***/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle(numRows, vector<int>());
        for (int i = 0; i < numRows; ++i)
            for (int j = 0; j <= i; ++j)
                triangle[i].push_back(((0 == j) || (i == j)) ? 1 : (triangle[i-1][j-1] + triangle[i-1][j]));
        return triangle;
    }
};