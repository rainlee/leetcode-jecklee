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