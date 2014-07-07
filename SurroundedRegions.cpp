/***
 * �۲��֪���������ϵ�'O'һ�����ܱ�'X'��Χ
 * ͬ�����ͱ߽��ϵ�'O'��ͨ��'OҲ���ܱ�'X'��Χ
 * ͨ��DFS / BFS �������󣬽��ͱ߽���ͨ��'O'�������ַ�'#'��ʶ
 * ������֮�󣬽�'#'��ԭΪ'O'����������Ϊ'#'
 * '#'һ������'O'����һ�������ѷ��ʣ�ȥ��
 * DFS �ᳬʱ����
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