/***
 * 同Longest Substring Without Repeating Characters
 * 题目是要在S找到所有L的连续子串，由L的元素组成的子串，可以乱序
 * 双指针 + hash 维护一个移动窗口
 * 遍历S，每次前进L中的字符串长度（等长），枚举起点
 * 遍从Llen的长度，检查是否是L的子串
 * 用一个map保存已经出现过的L和出现次数（可能重复）
 * 时间复杂度O(n*len)
 ***/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> vind;
        if ((0 == S.size()) || (0 == L.size()))
            return vind;
            
        int wlen = L[0].size();
        int Llen = wlen * L.size();
        
        if (S.size() < Llen)
            return vind;
        
        map<string, int> mdicL;
        for (int i = 0; i < L.size(); ++i)
            ++mdicL[L[i]];
        
        for (int i = 0; i <= S.size() - Llen; ++i)  // foreach the start of window; mind the right bound
        {
            map<string, int> mcntm;  // count matched
            int j;
            for (j = 0; j < Llen; j += wlen)  // wlen * wnum
            {
                string word = S.substr(i + j, wlen);
                if (mdicL.find(word) == mdicL.end())   // word not in L
                    break;
                    
                if (++mcntm[word] > mdicL[word])  // record the word; if word not in L, break
                    break;
            }
            if (j >= Llen)  // found
                vind.push_back(i);
        }
        return vind;
    }
};