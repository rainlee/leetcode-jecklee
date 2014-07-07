/***
 * 观察可知，四条边上的'O'一定不能被'X'包围
 * 同样，和边界上的'O'联通的'O也不能被'X'包围
 * 通过DFS / BFS 遍历矩阵，将和边界联通的'O'用特殊字符'#'标识
 * 遍历完之后，将'#'还原为'O'，其他都置为'#'
 * '#'一方面标记'O'，另一方面标记已访问，去重
 * DFS 会超时……
 ***/
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if ((0 == board.size()) || (0 == board[0].size()))
            return;
        const int m = board.size();
        const int n = board[0].size();
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (((0 == i) || (0 == j) || (m-1 == i) || n-1 == j) &&
                    ('O' == board[i][j]))
                    bfs(board, i, j);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = (board[i][j] == '#') ? 'O' : 'X';
        return;
    }
private:
    static void dfs(vector<vector<char>> &board, int row, int col) 
    {
        const int m = board.size();
        const int n = board[0].size();
        
        if ((row < 0) || (col < 0) || (row >= m) || (col >= n))
            return;
        
        if (board[row][col] != 'O')
            return;
        
        board[row][col] = '#';   // visit this node
        
        dfs(board, row-1, col);
        dfs(board, row+1, col);
        dfs(board, row, col-1);
        dfs(board, row, col+1);
        
        return;
    }
    
    static void bfs(vector<vector<char>> &board, int row, int col) 
    {
        const int m = board.size();
        const int n = board[0].size();
        
        queue<pair<int, int> > qpath;
        qpath.push(make_pair(row, col));
        
        while (!qpath.empty())
        {
            int row = qpath.front().first;
            int col = qpath.front().second;
            qpath.pop();
            
            if ((row < 0) || (col < 0) || (row > m-1) || (col > n-1) || (board[row][col] != 'O'))
                continue;
            board[row][col] = '#';   // visited
            
            qpath.push(make_pair(row-1, col));
            qpath.push(make_pair(row+1, col));
            qpath.push(make_pair(row, col-1));
            qpath.push(make_pair(row, col+1));
        }
        
        return;
    }
};