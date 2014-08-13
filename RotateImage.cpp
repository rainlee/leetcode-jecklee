/***
 * 法1：从外向里 一层层的旋转
 * 逆时针拷贝，边长为len，每条边拷贝长度为len-1
 * 时间复杂度O(n)
 ***/
/*
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
            
        const int n = matrix.size();
        for (int i = 0; i < n/2; ++i)
        {
            int len = n - 2*i;   // side length
            int k = i + len - 1; // rightest of the side
            for (int j = 0; j < len - 1; ++j)  // [0, len-1)
            {
                int tmp = matrix[i][i+j];   // copy in counterclockwise
                matrix[i][i+j] = matrix[k-j][i];
                matrix[k-j][i] = matrix[k][k-j];
                matrix[k][k-j] = matrix[i+j][k];
                matrix[i+j][k] = tmp;
            }
        }
        return;
    }
};
*/

/***
 * 法2：两次翻转
 * 先沿副对角线翻转，再沿水平中线翻转
 * 时间复杂度O(n)
 ***/
/*
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
            
        const int n = matrix.size();
        
        // rotate based on vice diagonal
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n-i; ++j)
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
        
        // rotate based on horizontal midline
        for (int i = 0; i < n/2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n-i-1][j]);
        return;
    }
};
*/

/***
 * 法2：两次翻转
 * 先沿水平中线翻转，再沿主对角线翻转
 * 时间复杂度O(n)
 ***/
/*
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
            
        const int n = matrix.size();
        
        // rotate based on horizontal midline
        for (int i = 0; i < n/2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n-i-1][j]);
        
        // rotate based on main diagonal
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
        return;
    }
};
*/

// 先上下翻转，再沿主对角线翻转
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        
        const int n = matrix.size();
        for (int i = 0; i < n/2; ++i)
            matrix[i].swap(matrix[n-i-1]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
        return;
    }
};