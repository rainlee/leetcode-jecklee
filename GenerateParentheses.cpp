/***
 * DFS
 * '(' ')'的递归深度分别为n
 * 当两者都达到n时，输出
 * 递归过程中要保证'('个数不少于')'
 ***/
/*
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(n, n, s);
        return vpares;
    }
private:
    vector<string> vpares;
    
    void dfs(int left, int right, string s)
    {
        if ((0 == left) && (0 == right))
        {
            vpares.push_back(s);
            return;
        }
        if (left > 0)
            dfs(left-1, right, s + "(");
        if (right > left)      // caution!!!
            dfs(left, right-1, s + ")");
        return;
    }
};
*/

/***
 * 法2：DFS，同法1
 * 优化，当left深度达到n时，right不用再递归处理了，直接补全剩余的')'
 ***/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(n, n, s);
        return vpares;
    }
private:
    vector<string> vpares;
    
    void dfs(int left, int right, string s)
    {
        if (0 == left)
        {
            s.append(right, ')');  // add left ')'
            vpares.push_back(s);
            return;
        }
            
        if (left > 0)
            dfs(left-1, right, s + '(');
        if (right > left)
            dfs(left, right-1, s + ')');
        return;
    }
};