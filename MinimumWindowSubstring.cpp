/***
 * 双指针 动态维护一个区间
 * 尾指针不断往后扫，当扫到有一个窗口包含所有的T的字符后
 * 收缩头指针，直到不能再收缩
 * 最后记录最小的窗口
 * 用两个计数器分别记录S T中的字母数，同时记录匹配的个数
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