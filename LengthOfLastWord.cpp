/***
 * 顺序扫描，记录每个word的长度
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
 * 注意开头和结尾的空格
 * 用last记录上一个有效字符长度
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