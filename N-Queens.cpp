/***
 * DFS �ݹ� ����
 * ÿ�δ���һ�У�����ÿһ���㣬�����/��/�Խ��� ���Ϸ������һ���ʺ�
 * ��һ�������¼ÿ��ѡ�����
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
// ��1����һ��ʵ��
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
 * ��2��DFS �ռ任ʱ��
 * �ڷ�1�Ļ����ϣ�ÿ�γ��˼�¼�ж�Ӧ����
 * ����¼��ѡ����С����Խ��ߡ����Խ���
 * ��(0,0)��ʼ������2*n-1�����Խ���
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
 * ��3������
 * �ؼ��ǻ�������
 * 1 ���һ�д�����
 * 2 ��ǰ��û�п�ѡ����
 * ���⣬��һ��ѡ���е�ʱ���0��ʼ������ʱҪ����һ��ѡ�����һ�п�ʼѡ
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
 * ��4��DFS��ʹ��λ���������ѡλ�ã��ο�http://www.matrix67.com/blog/archives/266
 * ���̴�����������row��ld��rd���ֱ��ʾ�����к������Խ��߷����������������һ�е���Щ�ط����ܷš�
 * �������������������õ��������еĽ�λ��ȡ����͵õ����п��Էŵ�λ��
 * ע��ݹ����ʱ���������ı仯��ÿ��������������һ����λ���������Խ��߷���Ľ�λ����һ�е�Ӱ����Ҫƽ��һλ��
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
// ��4����һ��ʵ��
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