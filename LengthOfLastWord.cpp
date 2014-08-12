/***
 * ˳��ɨ�裬��¼ÿ��word�ĳ���
 ***/
/*
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
*/

/***
 * ע�⿪ͷ�ͽ�β�Ŀո�
 * ��last��¼��һ����Ч�ַ�����
 ***/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int last = 0;
        int cnt = 0;
        while ('\0' != *s)
        {
            if (' ' == *s)
            {
                last = (cnt ? cnt : last);
                cnt = 0;
            }
            else
                ++cnt;
            ++s;
        }
        return (cnt ? cnt : last);
    }
};