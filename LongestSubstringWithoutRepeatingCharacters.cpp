/***
 * ̰�ķ�
 * ˫ָ�� + hash��ά��һ������
 * ��һ��map�����Ѿ��������ַ����ַ����ֵ�λ��
 * ������ַ��Ѿ����֣�����㵱ǰ���ڵĳ��ȣ��������ַ�λ�ã���������
 * ��¼��Ĵ��ڳ���
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