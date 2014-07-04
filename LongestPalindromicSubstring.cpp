/***
 * ����������У����Եõ�����t��Ȼ��s t��DP�������������
 * ������Ӵ�
 * ����ö�ٻ����е㣬Ȼ����������չ
 * ע������������Գƣ�Ҳ������ż���Գ�
 * ʱ�临�Ӷ�O(n^2)
 ***/
/*
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        
        maxl = 1;
        wstart = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            searchPal(s, 1, i-1, i+1);  // odd
            searchPal(s, 0, i-1, i);    // even
        }
        return s.substr(wstart, maxl);
    }
private:
    void searchPal(string &s, int len, int low, int high)
    {
        while ((low >= 0) && (high < s.size()) && (s[low] == s[high]))  // odd
        {
            len += 2;
            --low;
            ++high;
        }
        if (len > maxl)
        {
            maxl = len;
            wstart = low + 1;
        }
        return;
    }

    int maxl = 1;
    int wstart = 0;
};
*/

/***
 * ��2����̬�滮
 * dp[i][j] ��ʾ i��j�Ƿ��ǻ��� (j >= i)
 * dp[i][j] = dp[i+1][j-1] && (s[i] == s[j])
 * ��ʼ��i == jʱ dp[i][j] = true; 
 * j = i+1, dp[i][j] = (s[i] == s[j])
 * i > j ʱ���൱�ڿմ���Ҳ��Ϊ�ǻ��ģ�dp[i][j] = true
 * ʱ�临�Ӷ� O(n^2)
 ***/
/*
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        if (n <= 1)
            return s;
        
        //vector<vector<bool> > dp(s.size(), vector<bool>(false));
        bool dp[n][n];   // vector �ᳬʱ����
        fill_n(&dp[0][0], n*n, false);
        //for (int i = 0; i < s.size(); ++i)
        //    dp[i][i] = true;
        
        int maxl = 1;
        int wstart = 0;
        for (int j = 0; j < s.size(); ++j)
        {
            dp[j][j] = true;
            for (int i = 0; i < j; ++i) // [i, j]
            {
                if (j == i+1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = ((s[i] == s[j]) && dp[i+1][j-1]);
                if (dp[i][j])
                {
                    int len = j - i + 1;
                    if (len > maxl)
                    {
                        maxl = len;
                        wstart = i;
                    }
                }
            }
        }
        return s.substr(wstart, maxl);
    }
};
*/

// ���棬ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n^2)
// ��ʱ����
/*
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n * n, false);
        // ��vector �ᳬʱ
        //vector<vector<bool> > f(n, vector<bool>(n, false));
        size_t max_len = 1, start = 0; // ������Ӵ��ĳ��ȣ����
        for (size_t i = 0; i < s.size(); i++) {
            f[i][i] = true;
            for (size_t j = 0; j < i; j++) { // [j, i]
                f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                if (f[j][i] && max_len < (i - j + 1)) {
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
    }
};
*/

/***
 * ��3��O(n)���㷨 http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
 * ˼·�ͷ�1һ����ö�ٻ����е㣬��������չ
 * ������P[i]��¼��iΪ���ĵ�����Ĵ��ĳ��ȣ�����P[i]�Ļ��ĶԳ��Ա���һЩ�ظ�����
 * Ϊ���㴦������/ż���ԳƵ����������β��ÿ�����ַ��м����һ�������ַ�'#'
 * #b#a#b# �� #b#a#a#b# ȫ����Ϊ�����Գ�
 * P[3] = 3   P[4] = 4 ����һ��ĳ��ȸպõ���ȥ��'#'��ȫ�����ĳ���
 * ��ǰ���������P[i], ����¼�������ұ߽�R����Ӧ���е�C
 * �� R > i, ��i����CΪ�е�ĶԳ�λ��i_m�и��ԳƵ�
 *   ����i���ұ߳�R - i�Ĳ��� �� i_m����߳�R-i�Ĳ��ֶԳ�
 *     ��P[i_m] <= R-i, �����i_m�ĶԳƵ� ȫ����iΪ�е�R-iΪ�뾶�Ļ���
 *       i_m�ĶԳƵ�Ҳ��ͬ����������P[i] ���ٵ���P[i_m]��Ȼ������������չ
 *     ��P[i_m] > R-i���� P[i]���ٵ���R-i��Ȼ����������չ
 * ��R <= i, ��P[i]��0��ʼ��չ
 ***/
string preProcess(string s)
{
    int n = s.size();
    if (0 == n)
        return "^$";
    
    string t = "^";
    for (int i = 0; i < n; ++i)
        //t += "#" + s[i];
        t += "#" + s.substr(i, 1);
    t += "#$";
    
    return t;
}

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1)
            return s;
        
        string t = preProcess(s);
        n = t.size();
        
        vector<int> P(n, 0);
        int C = 0;
        int R = 0;
        int maxl = 0;
        int maxi = 0;
        for (int i = 1; i < n-1; ++i)
        {
            int i_m = 2*C - i;   // mirror
            
            P[i] = (R > i) ? min(P[i_m], R-i) : 0;
            
            while (t[i + P[i] + 1] == t[i - P[i] - 1])  // expand
                ++P[i];
            
            if (P[i] > maxl)  // mark the max len
            {
                maxl = P[i];
                maxi = i;
            }
            
            if (i + P[i] > R)  // mark the rightest index
            {
                C = i;
                R = i + P[i];
            }
        }
        return s.substr((maxi - 1 - maxl)/2, maxl);
    }
};