/***
 * 同N-Queens DFS
 * 法1：记录每行选择的列
 * 法2：记录每行选择的列，标记已选的列、两方向的对角线
 * 法3：迭代
 * 法4：位操作，row ld rd 三个位图标记已选的位置
 ***/

/*
// 法1
class Solution {
public:
    int totalNQueens(int n) {
        sum = 0;
        
        vector<int> vcols;
        dfs(n, 0, vcols);
        
        return sum;
    }
private:
    int sum;
    
    void dfs(int n, int row, vector<int> vcols)
    {
        if (n == row)  // the end
        {
            ++sum;
            return;
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (isValid(vcols, i))
            {
                vcols.push_back(i);
                dfs(n, row+1, vcols);
                vcols.pop_back();
            }
        }
        return;
    }
    bool isValid(vector<int> &vcols, int col)
    {
        int row = vcols.size();
        for (int i = 0; i < row; ++i)
            if ((vcols[i] == col) || ((row - i) == abs(col - vcols[i])))
                return false;
        
        return true;
    }
};
*/

/*
// 法2
class Solution {
public:
    int totalNQueens(int n) {
        sum = 0;
        bcol.resize(n, false);
        bld.resize(2*n, false);
        brd.resize(2*n, false);
        
        vector<int> vcols;
        dfs(n, 0, vcols);
        
        return sum;
    }
private:
    int sum;
    vector<bool> bcol;
    vector<bool> bld;   // left diag
    vector<bool> brd;   // right diag
    
    void dfs(int n, int row, vector<int> &vcols)
    {
        if (n == row)
        {
            ++sum;
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (!(bcol[i] || bld[row+i] || brd[row-i+n]))
            {
                bcol[i] = bld[row+i] = brd[row-i+n] = true;
                vcols.push_back(i);
                dfs(n, row+1, vcols);
                vcols.pop_back();
                bcol[i] = bld[row+i] = brd[row-i+n] = false;
            }
        }
        return;
    }
};
*/

/*
// 法3
class Solution {
public:
    int totalNQueens(int n) {
        int sum = 0;
        vector<int> vcols(n, -1);
        int row = 0;
        while (row >= 0)
        {
            if (row == n)
            {
                ++sum;
                --row;  // back tracking
            }
            int i = (vcols[row] == -1) ? 0 : (vcols[row] + 1);
            for ( ; i < n; ++i)
            {
                if (isValid(vcols, row, i))
                {
                    vcols[row++] = i;  // move on
                    break;             // next row
                }
            }
            if (i == n) // not found
                vcols[row--] = -1;    // back tracking
        }
        return sum;
    }
    bool isValid(vector<int> &vcols, int row, int col)
    {
        for (int i = 0; i < row; ++i)
            if ((col == vcols[i]) || ((row - i) == abs(col - vcols[i])) )
                return false;
        return true;
    }
};
*/


// 法4
class Solution {
public:
    int totalNQueens(int n) {
        sum = 0;
        vector<int> vcols;
        dfs(n, 0, 0, 0, vcols);
        return sum;
    }
private:
    int sum;
    
    void dfs(int n, int row, int ld, int rd, vector<int> &vcols)
    {
        if (row == ((1<<n) - 1))  // all 1
        {
            ++sum;
            return;
        }
        int valid = ~(row | ld | rd);
        for (int i = 0; i < n; ++i)
        {
            int pos = 1 << i;
            if (valid & pos)
            {
                vcols.push_back(i);
                dfs(n, row|pos, (ld|pos) << 1, (rd|pos) >> 1, vcols);
                vcols.pop_back();
            }
        }
        return;
    }
};

    
    