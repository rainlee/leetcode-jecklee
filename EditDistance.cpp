/***
 * DP
 * ����d[i, j] ��ʾword1��ǰi���ַ���word2��ǰj���ַ�����С�༭����
 * ��i�ַ�����3��;����Ϊj
 *           / d[i-1, j-1], word1[i] == word2[j]
 *           / d[i-1, j] + 1, delete, word2ɾ��i�ַ�
 * d[i, j] = - d[i, j-1] + 1, insert, word2����j�ַ�
 *           \ d[i-1, j-1] + 1, replace, word1[i] != word2[j]
 * ��ʼ�� d[0, j] = j; d[i, 0] = i
 * ע���ַ����ȴ�0~n������dp[]�� n+1
 ***/
/*
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        vector<vector<int> > dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 0; i <= n1; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= n2; ++j)
            dp[0][j] = j;
        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                if (word1[i-1] == word2[j-1])  // caution: index i-1
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
            }
        }
        return dp[n1][n2];
    }
};
*/

/***
 * ��2��DP + ��������
 * ֻ��Ҫ��¼�����������ݣ���һά����ʵ��
 * ��Ҫ��¼��ֵd[i, j-1] d[i-1, j] d[i-1, j-1]
 * ǰ���������Ը������飬d[i-1, j-1]��Ҫ����ı�����¼
 * upper_left  upper
 *  dp[j-1]    dp[j]
 ***/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        vector<int> dp(n2+1, 0);   // rolling array
        for (int j = 0; j <= n2; ++j)
            dp[j] = j;
        
        for (int i = 1; i <= n1; ++i)
        {
            int upper_left = dp[0];  // caution!!! save dp[i-1][j-1]
            dp[0] = i;               // init dp[i][0]
            for (int j = 1; j <= n2; ++j)
            {
                int upper = dp[j];   // upperleft for next j
                if (word1[i-1] == word2[j-1])
                    dp[j] = upper_left;
                else
                    dp[j] = min(min(dp[j], dp[j-1]), upper_left) + 1;
                upper_left = upper;  // update for next j
            }
        }
        return dp[n2];
    }
};