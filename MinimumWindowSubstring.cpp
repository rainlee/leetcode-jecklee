/***
 * ˫ָ�� ��̬ά��һ������
 * βָ�벻������ɨ����ɨ����һ�����ڰ������е�T���ַ���
 * ����ͷָ�룬ֱ������������
 * ����¼��С�Ĵ���
 * �������������ֱ��¼S T�е���ĸ����ͬʱ��¼ƥ��ĸ���
 ***/
class Solution {
public:
    string minWindow(string S, string T) {
        if (S.empty() || (S.size() < T.size()))
            return "";
        
        int cnts[256] = {0}; // count of S
        int cntt[256] = {0}; // count of T
        
        for (int i = 0; i < T.size(); ++i)
            ++cntt[T[i]];
        
        int minw = INT_MAX;
        int mins = 0;        // start of min window
        int wstart = 0;      // start of window
        int cntm = 0;        // count of matched alpha
        
        for (int wend = 0; wend < S.size(); ++wend)  // sliding window
        {
            if (cntt[S[wend]] > 0)  // S[wend] is in T
            {
                ++cnts[S[wend]];
                if (cnts[S[wend]] <= cntt[S[wend]])  // one more matched alpha
                    ++cntm;
            }
            if (cntm == T.size())  // get a matched window
            {
                while ((cnts[S[wstart]] > cntt[S[wstart]]) || (0 == cntt[S[wstart]]))  // narrow the window
                {
                    --cnts[S[wstart]];
                    ++wstart;
                }
                int wnd = wend - wstart + 1;   // update min window
                if (wnd < minw)
                {
                    minw = wnd;
                    mins = wstart;
                }
            }
        }
        if (INT_MAX == minw)
            return "";
        else
            return S.substr(mins, minw);
    }
};