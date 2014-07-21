/***
 * DFS
 * '(' ')'�ĵݹ���ȷֱ�Ϊn
 * �����߶��ﵽnʱ�����
 * �ݹ������Ҫ��֤'('����������')'
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
 * ��2��DFS��ͬ��1
 * �Ż�����left��ȴﵽnʱ��right�����ٵݹ鴦���ˣ�ֱ�Ӳ�ȫʣ���')'
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