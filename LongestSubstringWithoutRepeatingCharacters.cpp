/***
 * 贪心法
 * 双指针 + hash，维护一个区间
 * 用一个map保存已经遍历的字符和字符出现的位置
 * 如果该字符已经出现，则计算当前窗口的长度，并更新字符位置，滑动窗口
 * 记录最长的窗口长度
 ***/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (0 == s.size())
            return 0;
        
        map<char, int> mmap;
        
        int maxw = 0;
        int wstart = 0;
        for (int wend = 0; wend < s.size(); ++wend)
        {
            map<char, int>::iterator it = mmap.find(s[wend]);
            if ((it != mmap.end()) && (it->second >= wstart))  // repeat char
            {
                int window = wend - wstart;  // update min window
                wstart = it->second + 1;     // index of pre char + 1
                if (window > maxw)
                    maxw = window;
            } // else
            mmap[s[wend]] = wend;  // if exist, update; else, add a new entry
        }
        maxw = max(maxw, (int)(s.size() - wstart));   // caution: the last seg!!
        
        return maxw;
    }
};