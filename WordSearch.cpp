/***
 * 遍历二维矩阵，对每个点进DFS
 * 用一个二维数组记录点是否已经被访问
 ***/
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty())
            return false;
        
        const int m = board.size();
        const int n = board[0].size();
        
        vector<vector<bool> > vvvisited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (dfs(board, word, 0, i, j, vvvisited))
                    return true;
        
        return false;
    }
private:
    static bool dfs(vector<vector<char> > &board, const string &word, 
                    int deep, int x, int y, vector<vector<bool> > &vvvisited) 
    {
        if (deep == word.size())   // pop
            return true;
        
        if ( (x < 0) || (x >= board.size()) ||
             (y < 0) || (y >= board[0].size()) )
            return false;
        
        if (vvvisited[x][y])  // caution: has been visited, cant be visited again
            return false;
        
        if (board[x][y] != word[deep])   // cur deep
            return false;
        
        vvvisited[x][y] = true;   // ==, visit the node
        bool bfound = dfs(board, word, deep+1, x-1, y, vvvisited) ||   // up
                      dfs(board, word, deep+1, x+1, y, vvvisited) ||   // down
                      dfs(board, word, deep+1, x, y-1, vvvisited) ||   // left
                      dfs(board, word, deep+1, x, y+1, vvvisited);     // right
        vvvisited[x][y] = false;  // restore
        
        return bfound;
    }
};

// 以下用dfs bfs两种方法遍历矩阵
// BFS是错误的，反例
// ["ABCE","SFES","ADEE"], "ABCESEEEFS"，应该返回true，bfs返回false
// ["AB","BC"], "ABCB"
// 因为bfs每次将周围可访问点都标记为已访问true，而实际上这时候还没有访问到该点……
static int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() || board[0].empty())  return false;
        return exist_1(board, word);
    }
private:
    // DFS
    bool dfs(vector<vector<char> > &board, int x, int y, string &word, int k, vector<vector<bool> > &visited) {
        if (k == word.size())
            return true;
            
        const int n = board.size();
        const int m = board[0].size();
        if ((x < 0) || (x >= n) || (y < 0) || (y >= m) || visited[x][y] || (board[x][y] != word[k]))
            return false;
        
        bool bres = false;    
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i)
        {
            int x2 = x + directions[i][0];
            int y2 = y + directions[i][1];
            if (dfs(board, x2, y2, word, k+1, visited))
            {
                bres = true;
                break;
            }
        }
        visited[x][y] = false;
        return bres;
    }
    bool exist_1(vector<vector<char> > &board, string &word) {
        const int n = board.size();
        const int m = board[0].size();
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (dfs(board, i, j, word, 0, visited))
                    return true;
        return false;
    }
    
    // BFS
    struct Node {
        int x;
        int y;
        Node(int x, int y): x(x), y(y) {}
    };
    bool bfs(vector<vector<char> > &board, int x, int y, string &word) {
        const int n = board.size();
        const int m = board[0].size();
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        queue<pair<Node, int> > q;  // node - step
        q.push(make_pair(Node(x, y), 0));
        visited[x][y] = true;
        while (!q.empty())
        {
            int x1 = q.front().first.x;
            int y1 = q.front().first.y;
            int step = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int x2 = x1 + directions[i][0];
                int y2 = y1 + directions[i][1];
                if ((x2 < 0) || (x2 >= n) || (y2 < 0) || (y2 >= m) || visited[x2][y2] || (board[x2][y2] != word[step+1]))
                    continue;
                if (step+1 == word.size()-1)
                    return true;
                q.push(make_pair(Node(x2, y2), step+1));
                visited[x2][y2] = true;
            }
        }
        return false;
    }
    bool exist_2(vector<vector<char> > &board, string &word) {
        const int n = board.size();
        const int m = board[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if ((board[i][j] == word[0]) && ((word.size() == 1) || bfs(board, i, j, word)))
                    return true;
        return false;
    }
};