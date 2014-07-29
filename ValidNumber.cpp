/***
 * 有大神用状态机搞定，膜拜…… https://github.com/rainlee/LeetCode-1/blob/master/ValidNumber.h
 * 分析字符串中的几种特殊元素，分别用变量去标记
 * space, 空格，只能在开头和结尾有空格（去掉开头的空格）
 * neg, 正负号，可能出现在开头或者e后面
 * num, 数字，必须要有数字
 * dot, 小数点，只能有一个，不能在e后
 * exp, e科学计数法，只能有一个，前面必须有数字，后面必须有数字（可能有+ -）
 ***/
class Solution {
public:
    bool isNumber(const char *s) {
        if (NULL == s)
            return false;
        while (' ' == *s)  // skip spaces in the head
            ++s;
        
        if (('+' == *s) || ('-' == *s))
            ++s;
        
        bool space = false;
        bool num = false;
        bool dot = false;
        bool exp = false;
        
        while (*s != '\0')
        {
            if (' ' == *s)
                space = true;
            else if (space)   // space must in the end
                return false;
            else if (isdigit(*s))
                num = true;
            else if ('.' == *s)
            {
                if (dot || exp)   // only have one dot, and cant after 'e'
                    return false;
                dot = true;
            }
            else if (('e' == *s) || ('E' == *s))
            {
                if (exp || !num)  // only have one exp, and must have valid num before
                    return false;
                exp = true;
                num = false;  // must have number after 'e'
                if (('+' == *(s+1)) || ('-' == *(s+1)))  // skip + -
                    ++s;
            }
            else    // invalid char
                return false;
            ++s;    // move on
        }
        return num;  // maybe false
    }
};