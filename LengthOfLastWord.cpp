/***
 * ˳��ɨ�裬��¼ÿ��word�ĳ���
 ***/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while (*s)
        {
            if (*s++ != ' ')   // s++
                ++len;
            else if (*s && (*s != ' '))
                len = 0;
        }
        return len;
    }
};