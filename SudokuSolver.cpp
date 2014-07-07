/***
 * 递归 回溯
 * 按行遍历，遇到'.' 则枚举9个数
 * 检查若合法，则递归处理
 ***/
const int N = 9;
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        doSudoku(board);
    }
private:
    static bool doSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if ('.' == board[i][j])
                {
                    for (char c = '1'; c <= '9'; ++c)
                    {
                        board[i][j] = c;
                        if (isValid(board, i, j) && doSudoku(board))  // recursive
                            return true;
                        board[i][j] = '.';   // back tracking
                    }
                    return false;   // 0-9 are all illegal
                }
            }
        }
        return true;
    }
    // check (x, y)
    static bool isValid(const vector<vector<char> > &board, int x, int y)
    {
        // check row
        for (int i = 0; i < N; ++i)
            if ((i != x) && (board[i][y] == board[x][y]))
                return false;
        
        // check col
        for (int j = 0; j < N; ++j)
            if ((j != y) && (board[x][j] == board[x][y]))
                return false;
        
        // check box
        int xbox = (x / 3) * 3;
        int ybox = (y / 3) * 3;
        for (int i = xbox; i < xbox+3; ++i)
            for (int j = ybox; j < ybox+3; ++j)
                if ( ((i != x) || (j != y)) && (board[i][j] == board[x][y]) )
                    return false;
        
        return true;
    }
};