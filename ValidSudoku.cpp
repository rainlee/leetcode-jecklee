/***
 * �ֱ����С��С��飨3*3��
 ***/
/*
const int N = 9;
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        return isValidRow(board) && isValidCol(board) && isValidBox(board);
    }
private:
    static bool isValidRow(vector<vector<char> > &board)
    {
        for (int i = 0; i < N; ++i)
        {
            vector<bool> bused(N, false);
            for (int j = 0; j < N; ++j)
            {
                if ('.' == board[i][j])
                    continue;
                else if (bused[board[i][j] - '1'])
                    return false;
                else
                    bused[board[i][j] - '1'] = true;
            }
        }
        return true;
    }
    static bool isValidCol(vector<vector<char> > &board)
    {
        for (int j = 0; j < N; ++j)
        {
            vector<bool> bused(N, false);
            for (int i = 0; i < N; ++i)
            {
                if ('.' == board[i][j])
                    continue;
                else if (bused[board[i][j] - '1'])
                    return false;
                else
                    bused[board[i][j] - '1'] = true;
            }
        }
        return true;
    }
    static bool isValidBox(vector<vector<char> > &board)
    {
        for (int i = 0; i < N; i += 3)
            for (int j = 0; j < N; j += 3)
                if (!isValidOneBox(board, i, j))
                    return false;
        return true;
    }
    static bool isValidOneBox(vector<vector<char> > &board, int x, int y)
    {
        vector<bool> bused(N, false);
        for (int i = x; i < x+3; ++i)
        {
            for (int j = y; j < y+3; ++j)
            {
                if ('.' == board[i][j])
                    continue;
                else if (bused[board[i][j] - '1'])
                    return false;
                else
                    bused[board[i][j] - '1'] = true;
            }
        }
        return true;
    }
};
*/

/***
 * λ���� ֻ��Ҫһ�α���
 * ��һλ��ʾһ�����֣������row����col[]����box[]
 * ���ʵ�ĳһλ������Ӧλ�Ƿ�Ϊ1����Ϊ1�򲻺Ϸ�
 * ���򽫸�λ��1
 * ʱ�临�Ӷ�O(n) �ռ临�Ӷ� O(sizeof(int) * (1 + 9 + 9)) = O(1)
 ***/
const int N = 9;
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int row = 0;
        vector<int> col(N, 0);
        vector<int> box(N, 0);
        
        for (int i = 0; i < N; ++i)
        {
            row = 0;   // init
            for (int j = 0; j < N; ++j)
            {
                if ('.' == board[i][j])
                    continue;
                
                int bit = 1 << (board[i][j] - '1');   // visited bit
                int ibox = i/3 * 3 + j/3;
                
                if ( (row & bit) || (col[j] & bit) || (box[ibox] & bit) )  // check bit
                    return false;
                
                row |= bit;
                col[j] |= bit;
                box[ibox] |= bit;
            }
        }
        return true;
    }
};