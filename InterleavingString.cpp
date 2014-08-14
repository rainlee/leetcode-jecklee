/***
 * ��̬�滮
 * dp[i][j] ��ʾs3 ��ǰ i+j ���ַ��Ƿ�����s1��ǰi����s2��ǰj���ַ����
 *            / dp[i-1][j], if s1[i-i] == s3[i+j-1]
 * dp[i][j] = 
 *            \ dp[i][j-1], if s2[j-i] == s3[i+j-1]
 ***/
/*
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int n1 = s1.size();
        const int n2 = s2.size();
        const int n3 = s3.size();
        if (n1 + n2 != n3)
            return false;
        if (!n1)
            return (s3.compare(s2) == 0);
        if (!n2)
            return (s3.compare(s1) == 0);
        vector<vector<bool> > dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0] = true;   // init
        for (int i = 0; i <= n1; ++i)
        {
            for (int j = 0; j <= n2; ++j)
            {
                if ((0 == i) && (0 == j))
                    continue;
                else if (0 == i)
                    dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);
                else if (0 == j)
                    dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
                else
                    dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[i+j-1])) ||
                               (dp[i-1][j] && (s1[i-1] == s3[i+j-1]));
            }
        }
        return dp[n1][n2];
    }
};
*/

/***
 * ��2��DP + ��������
 * ��һ��һά�����������¼��һ�к͵�ǰ�е�dp
 ***/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int n1 = s1.size();
        const int n2 = s2.size();
        const int n3 = s3.size();
        if (n1 + n2 != n3)
            return false;
        if (!n1)
            return (s3.compare(s2) == 0);
        if (!n2)
            return (s3.compare(s1) == 0);
        
        vector<bool> dp(n2+1, false);
        dp[0] = true;
        for (int i = 0; i <= n1; ++i)
        {
            for (int j = 0; j <= n2; ++j)
            {
                if ((0 == i) && (0 == j))
                    continue;
                else if (0 == i)
                    dp[j] = dp[j-1] && (s2[j-1] == s3[i+j-1]);
                else if (0 == j)
                    dp[j] = dp[j] && (s1[i-1] == s3[i+j-1]);
                else
                    dp[j] = (dp[j-1] && (s2[j-1] == s3[i+j-1])) ||
                            (dp[j] && (s1[i-1] == s3[i+j-1]));
            }
        }
        return dp[n2];
    }
};