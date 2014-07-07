/***
 * DFS
 * ö�ٷָ�㣬��n-1���ָ�㣬��ÿһ���ж��Ƿ��ǻ���
 * DFS��������startΪ���������Ӵ�
 * ��2^(n-1)��ѡ��
 * ʱ�临�Ӷ� O(2^n)
 ***/
/*
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, 0, path);
        
        return vvpals;
    }
private:
    vector<vector<string> > vvpals;
    
    void dfs(string &s, int start, vector<string> &path)
    {
        if (start == s.size())  // find a full path
        {
            vvpals.push_back(path);
            return;
        }
        
        for (int i = start; i < s.size(); ++i)  // enum substring
        {
            string ssub = s.substr(start, i-start+1);
            if (isPalindrome(ssub))
            {
                path.push_back(ssub);
                dfs(s, i + 1, path);
                path.pop_back();      // restore
            }
        }
        return;
    }
    
    static bool isPalindrome(string &s)
    {
        int low = 0;
        int high = s.size() - 1;
        while (low < high)
            if (s[low++] != s[high--])
                return false;
        return true;
    }
};
*/

/***
 * �ж��ַ������Ӵ��Ƿ���palindrome������DPʵ��
 * dp[i][j] ������¼�Ӵ�s[i,j]�Ƿ��ǻ��ĵ�
 * ��ʼ�� i == j һ���ǻ���
 * ת�Ʒ���
 * dp[i][j] = (s[i] == s[j]) && ((j-i < 2) || dp[i+1][j-1]), i E [0, n), j E [i, n)
 * ���dp���ľ���֮��ʹ��DFS�����������
 ***/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int n = s.size();
        
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        getPalindrome(s, dp);
        
        vector<string> path;
        dfs(s, dp, 0, path);
        
        return vvpals;
    }
private:
    vector<vector<string> > vvpals;
    
    void getPalindrome(string &s, vector<vector<bool> > &dp)
    {
        //for (int i = 0; i < s.size(); ++i)
        for (int i = s.size()-1; i >= 0; --i)
            for (int j = i; j < s.size(); ++j)
                dp[i][j] = (s[i] == s[j]) && ((j-i < 2) || dp[i+1][j-1]);
        return;
    }
    
    void dfs(string &s, vector<vector<bool> > &dp, int start, vector<string> &path)
    {
        if (start == s.size())
        {
            vvpals.push_back(path);
            return;
        }
        
        for (int j = start; j < s.size(); ++j)
        {
            if (dp[start][j])  // can break here
            {
                path.push_back(s.substr(start, j - start + 1));
                dfs(s, dp, j+1, path);
                path.pop_back();
            }
        }
        return;
    }
};