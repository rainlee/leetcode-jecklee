/***
 * DFS 递归 回溯
 * 每次处理一行，遍历每一个点，检查行/列/对角线 若合法则放置一个皇后
 * 用一个数组记录每行选择的列
 ***/
/*
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> vcols;
        dfs(n, 0, vcols);
        return vvsols;
    }
private:
    vector<vector<string> > vvsols;
    
    void dfs(int n, int row, vector<int> &vcols)
    {
        if (row == n)  // the end
        {
            vector<string> vsol;
            for (int i = 0; i < n; ++i)
            {
                string srow(n, '.');
                srow[vcols[i]] = 'Q';   // row: i, col: vcols[i] 
                vsol.push_back(srow);
            }
            vvsols.push_back(vsol);
            return;
        }
        
        // check each col
        for (int j = 0; j < n; ++j)
        {
            if (isValid(vcols, j))  // choose the col: j
            {
                vcols.push_back(j);
                dfs(n, row+1, vcols);
                vcols.pop_back();     // back tracking
            }
        }
        return;
    }
    
    // check row col, main and anti diagonal line
    bool isValid(vector<int> &vcols, int col)
    {
        int row = vcols.size();
        for (int i = 0; i < row; ++i)  // (row, col) vs (i, vcols[i])
            if ((vcols[i] == col) || ((row - i) == (abs(col - vcols[i]))))  // abs - main and anti diag
                return false;
        
        return true;
    }
};
*/

/*
// 法1的另一种实现
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        if (0 == n)
            return nqueens;
        vcols.resize(n);
        vector<string> path;
        dfs(n, path);
        return nqueens;
    }
private:
    vector<int> vcols;
    vector<vector<string> > nqueens;
    
    void dfs(int n, vector<string> &path)
    {
        if (n == path.size())
        {
            nqueens.push_back(path);
            return;
        }
        int deep = path.size();
        for (int j = 0; j < n; ++j)
        {
            if (check(deep, j))
            {
                vcols[deep] = j;    // set the choosen col
                string srow(n, '.');
                srow[j] = 'Q';
                path.push_back(srow);
                dfs(n, path);
                path.pop_back();
            }
        }
        return;
    }
    bool check(int deep, int j)
    {
        for (int i = 0; i < deep; ++i)
            if ((j == vcols[i]) || ((deep - i) == abs(j - vcols[i])))
                return false;
        return true;
    }
};
*/

/***
 * 法2：DFS 空间换时间
 * 在法1的基础上，每次除了记录行对应的列
 * 还记录已选择的列、正对角线、反对角线
 * 从(0,0)开始，共有2*n-1条正对角线
 ***/
/*
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        bcol.resize(n, false);
        bmainDiag.resize(2*n, false);
        bantiDiag.resize(2*n, false);
        
        vector<int> vcols;
        dfs(n, 0, vcols);
        return vvsols;
    }
private:
    vector<bool> bcol;
    vector<bool> bmainDiag;
    vector<bool> bantiDiag;
    vector<vector<string> > vvsols;
    
    void dfs(int n, int row, vector<int> &vcols)
    {
        if (row == n)  // the end
        {
            vector<string> vsol;
            for (int i = 0; i < n; ++i)
            {
                string srow(n, '.');
                srow[vcols[i]] = 'Q';   // row: i, col: vcols[i] 
                vsol.push_back(srow);
            }
            vvsols.push_back(vsol);
            return;
        }
        
        // check each col
        for (int j = 0; j < n; ++j)
        {
            if (isValid(row, j, n))  // choose the col: j
            {
                bcol[j] = bmainDiag[row+j] = bantiDiag[row-j+n] = true;
                vcols.push_back(j);
                dfs(n, row+1, vcols);
                vcols.pop_back();     // back tracking
                bcol[j] = bmainDiag[row+j] = bantiDiag[row-j+n] = false;
            }
        }
        return;
    }
    
    // check row col, main and anti diagonal line
    bool isValid(int row, int col, int n)
    {
        return !(bcol[col] || bmainDiag[row + col] || bantiDiag[row - col + n]);
    }
};
*/

/***
 * 法3：迭代
 * 关键是回溯条件
 * 1 最后一行处理完
 * 2 当前行没有可选的列
 * 另外，第一次选择列的时候从0开始，回溯时要从上一次选择的下一列开始选
 ***/
/*
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > vvsols;
        
        vector<int> vcols(n, -1);
        int row = 0;
        while (row >= 0)
        {
            if (row == n)  // found one
            {
                vector<string> vsol;
                for (int i = 0; i < n; ++i)
                {
                    string srow(n, '.');
                    srow[vcols[i]] = 'Q';   // row: i, col: vcols[i] 
                    vsol.push_back(srow);
                }
                vvsols.push_back(vsol);
                --row;       // back tracking, continue
            }
            
            int i = (vcols[row] == -1) ? 0 : (vcols[row] + 1);  // move on
            for ( ;i < n; ++i)
            {
                if (isValid(vcols, row, i))
                {
                    vcols[row] = i;
                    ++row;           // move on
                    break;
                }
            }
            if (i == n)  // not found in cur row
            {
                vcols[row] = -1;
                --row;    // back tracking
            }
        }
        return vvsols;
    }
private:
    // check row col, main and anti diagonal line
    bool isValid(vector<int> &vcols, int row, int col)
    {
        for (int i = 0; i < row; ++i)  // (row, col) vs (i, vcols[i])
            if ((vcols[i] == col) || ((row - i) == (abs(col - vcols[i]))))  // abs - main and anti diag
                return false;
        
        return true;
    }
};
*/

/***
 * 法4：DFS，使用位操作标记已选位置，参考http://www.matrix67.com/blog/archives/266
 * 过程带三个参数，row、ld和rd，分别表示在纵列和两个对角线方向的限制条件下这一行的哪些地方不能放。
 * 把它们三个并起来，得到该行所有的禁位，取反后就得到所有可以放的位置
 * 注意递归调用时三个参数的变化，每个参数都加上了一个禁位，但两个对角线方向的禁位对下一行的影响需要平移一位。
 ***/
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> vcols;
        dfs(n, 0, 0, 0, vcols);
        return vvsols;
    }
private:
    vector<vector<string> > vvsols;
    
    void dfs(int n, int row, int ld, int rd, vector<int> &vcols)
    {
        if (row == ((1<<n) - 1))  // end with all 1 
        {
            vector<string> vsol;
            for (int i = 0; i < n; ++i)
            {
                string srow(n, '.');
                srow[vcols[i]] = 'Q';   // row: i, col: vcols[i] 
                vsol.push_back(srow);
            }
            vvsols.push_back(vsol);
            return;
        }
        
        int valid = ~ (row | ld | rd);
        for (int i = 0; i < n; ++i)
        {
            int pos = 1 << i;
            if (valid & pos)   // is valid
            {
                vcols.push_back(i);
                dfs(n, row|pos, (ld|pos) << 1, (rd|pos) >> 1, vcols);
                vcols.pop_back();     // back tracking
            }
        }
        return;
    }
};

/*
// 法4的另一种实现
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        if (0 == n)
            return nqueens;
        vcols.resize(n);
        vector<string> path;
        dfs(n, 0, 0, 0, path);
        return nqueens;
    }
private:
    vector<int> vcols;
    vector<vector<string> > nqueens;
    
    void dfs(int n, int col, int ld, int rd, vector<string> &path)
    {
        if (col == ((1<<n) - 1))
        {
            nqueens.push_back(path);
            return;
        }
        int bvalid = ~(col | ld | rd);
        for (int j = 0; j < n; ++j)
        {
            int pos = 1 << j;
            if (bvalid & pos)
            {
                vcols[path.size()] = j;
                string srow(n, '.');
                srow[j] = 'Q';
                path.push_back(srow);
                dfs(n, col|pos, (ld|pos) >> 1, (rd|pos) << 1, path);
                path.pop_back();
            }
        }
        return;
    }
};
*/