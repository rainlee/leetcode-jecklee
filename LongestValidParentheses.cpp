/***
 * ��1��ջ
 * ջ�д�ŵ�����δ��ƥ���'('������
 * ��s[i] == '('����ջ
 * ��s[i] == ')'����ջ�ǿ�ʱ��ƥ�䣬��ջ����ʱջ����Ԫ������δ��ƥ��ģ�
 *     ջ����i֮��Ķ��Ѿ�ƥ�䣬ƥ�䳤��Ϊi - s.top()
 *     ��ջΪ�գ�˵����ȫƥ�䣬��ʱƥ�䳤��Ϊi - last��last����һ��ʧ��㣩
 *               ����()()���ڶ���')'ʱ��last = 0��ƥ�䳤����4����2
 * ��s[i] == ')'����ջΪ��ʱ��ʧ�䣬��¼last
 ***/
/*
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> spare;   // save index
        
        int last = -1;  // first mismatch pos
        int maxl = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                spare.push(i);
            else
            {
                if (spare.empty())  // mismatch
                    last = i;
                else
                {
                    spare.pop();    // match
                    maxl = max(maxl, spare.empty() ? (i - last) : (i - spare.top()));
                }
            }
        }
        return maxl;
    }
};
*/

/***
 * ��2��DP
 * dp[i]��ʾ��s[i]��s[n - 1]����s[i]�������Чƥ�������Ӵ�����
 * ��ʼ��dp[n-1] = 0
 * i��n - 2 -> 0������dp[]������¼�����ֵ��
 * ��s[i] == '('������s�д�i��ʼ��n - 1����dp[i]��ֵ����������Ϊ������
 *  - ��s��Ѱ�Ҵ�i + 1��ʼ����Ч����ƥ���Ӵ����ȣ���dp[i + 1]�����������Ч�������Ӵ����鿴��һ���ַ���
 *    ���±�Ϊj = i + 1 + dp[i + 1]����jû��Խ�磬����s[j] == ��)������s[i ... j]Ϊ��Ч����ƥ�䣬dp[i] =dp[i + 1] + 2
 *  - �������s[i ... j]����Чƥ�䳤��֮����j + 1û��Խ�磬��dp[i]��ֵ��Ҫ���ϴ�j + 1��ʼ�����Чƥ�䣬��dp[j + 1]��
 *    ���磬(())()
 ***/
/*
class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        vector<int> dp(n, 0);
        
        int maxl = 0;
        for (int i = n-2; i >= 0; --i)
        {
            int j = i + dp[i+1] + 1;   // index matched with i
            if ((s[i] == '(') && (j < n) && (s[j] == ')'))   // [i, ..., j]match
            {
                dp[i] = dp[i+1] + 2;
                if (j + 1 < n)       // maybe match
                    dp[i] += dp[j+1];
                maxl = max(maxl, dp[i]);
            }
        }
        return maxl;
    }
};
*/

/***
 * ��3��DP ͬ��2
 * ��ǰ�����㣬dp[i]��ʾs[0, i]���ƥ�䳤��
 ***/
class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        vector<int> dp(n, 0);
        
        int maxl = 0;
        for (int i = 1; i < n; ++i)
        {
            int j = i - dp[i-1] - 1;
            if ((s[j] == '(') && (j >= 0) && (s[i] == ')'))  // match
            {
                dp[i] = dp[i-1] + 2;
                if (j - 1 >= 0)
                    dp[i] += dp[j-1];
                maxl = max(maxl, dp[i]);
            }
        }
        return maxl;
    }
};