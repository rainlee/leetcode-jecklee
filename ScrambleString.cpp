/***
 * ��1���ݹ� + ��֦ ö�ٷָ��  O(n^6)?
 * ���ܵķָ�㣺1 ~ len-1
 * ��ÿ���ָ�㣬�о���Ͳ���������������ֱ�ݹ�
 * ��֦��
 * ��ÿ����������ȼ��s1 s2�Ƿ���ͬ������ֱͬ�ӷ���true
 * ����ͳ��ÿ����ĸ����ĸ������ͬ�������ָ�
 ***/
/*
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        
        if (s1 == s2)     // O(n)
            return true;
        
        // cnt each alpha
        int cnt[26] = {0};
        for (int i = 0; i < s1.size(); ++i)
            ++cnt[s1[i] - 'a'];
        for (int i = 0; i < s2.size(); ++i)
            --cnt[s2[i] - 'a'];
        for (int i = 0; i < 26; ++i)
            if (0 != cnt[i])
                return false;
            
        // enum the pos of partition
        for (int i = 1; i < s1.size(); ++i)
            if ( (isScramble(s1.substr(0, i), s2.substr(0, i)) &&          // same
                  isScramble(s1.substr(i), s2.substr(i))) ||
                 (isScramble(s1.substr(0, i), s2.substr(s2.size()-i)) &&   // symmetric
                  isScramble(s1.substr(i), s2.substr(0, s2.size()-i))) )
                return true;
        return false;
    }
};
*/

/***
 * ��2����̬�滮
 * dp[k][i][j] ��ʾ s1��i��ʼk���ַ� �� s2��j��ʼk���ַ� �Ƿ�Ϊ scrambled string
 *              / (s1[i] == s2[j]), k=1
 * dp[k][i][j] =                   ö�ٷָ��l(1 <= l <= k-1)�������Ҳ���ת�ͷ�ת�����������
 *              \ (dp[l][i][j] && dp[k-l][i+l][j+l]) || ((dp[l][i][j+k-l] && dp[k-l][i+l][j]))
 * ʱ�临�Ӷ�O(n^3)?
 ***/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        
        if (s1 == s2)     // O(n)
            return true;
    
        int n = s1.size();
        
        vector<vector<vector <bool> > > dp(n+1, vector<vector<bool> >(n, vector<bool>(n, false)));  // k: 1~n
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[1][i][j] = (s1[i] == s2[j]);
        
        for (int k = 2; k <= n; ++k)
        {
            for (int i = 0; i <= n-k; ++i)
            {
                for (int j = 0; j <= n-k; ++j)
                {
                    for (int l = 1; l < k; ++l)  // enum the partition point
                    {
                        if ( (dp[l][i][j] && dp[k-l][i+l][j+l]) || ((dp[l][i][j+k-l] && dp[k-l][i+l][j])) )
                        {
                            dp[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};