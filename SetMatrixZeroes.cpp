/***
 * 设置两个数组，标记每行每列是否存在0
 * 先遍历一遍，再根据标记数组来置0
 * 时间复杂度O(m*n), 空间复杂度O(m+n)
 ***/
/*
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (0 == matrix.size())
            return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<bool> vrow(m, false);
        vector<bool> vcol(n, false);
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (0 == matrix[i][j])
                {
                    vrow[i] = true;
                    vcol[j] = true;
                }
            }
        }
        
        for (int i = 0; i < m; ++i)
            if (vrow[i])
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
        
        for (int j = 0; j < n; ++j)
            if (vcol[j])
                for (int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
        
        return;
    }
};
*/

/***
 * 法2：思路同法1，复用matrix的第一行 第一列，作为标记数组
 * 另外需要两个变量来标记第一行第一列 是否有0
 * 时间复杂度O(m*n), 空间复杂度O(1)
 ***/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (0 == matrix.size())
            return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool brow0 = false;  // first row has 0 or not
        bool bcol0 = false;  // first col has 0 or not
        
        for (int j = 0; j < n; ++j)  // first row
        {
            if (0 == matrix[0][j])
            {
                brow0 = true;
                break;
            }
        }
        for (int i = 0; i < m; ++i)  // first col
        {
            if (0 == matrix[i][0])
            {
                bcol0 = true;
                break;
            }
        }
        
        for (int i = 1; i < m; ++i) // other rows and cols
            for (int j = 1; j < n; ++j)
                if (0 == matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
        
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if ((0 == matrix[0][j]) || (0 == matrix[i][0]))  // first row || first col
                    matrix[i][j] = 0;
        
        if (brow0)
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        
        if (bcol0)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        
        return;
    }
};