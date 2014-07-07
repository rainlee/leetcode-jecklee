/***
 * ��̬�滮
 * dp[i] ��ʾs�е�ǰi���ܷ���dict��ʾ
 * Ȼ��ö��i֮ǰ��i��β���Ӵ�[j,i+1]�Ƿ�����dict && dp[j]�Ƿ�����dict��ʾ
 * dp[i] = U{dp[j] && s.substring[j, i+1] E dict, j E [0, i) }
 ***/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        const int n = s.size();
        vector<bool> dp(n+1, false);  // 0 - n
        
        dp[0] = true;
        for (int i = 1; i <= n; ++i)  // len
        {
            for (int j = i-1; j >= 0; --j)
            {
                dp[i] = dp[j] && (dict.find(s.substr(j, i-j)) != dict.end());
                if (dp[i])
                    break;
            }
        }
        return dp[n];
    }
};