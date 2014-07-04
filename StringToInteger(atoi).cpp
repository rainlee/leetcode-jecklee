/***
 * 注意处理特殊情况，从前往后
 * 1 去掉前面多余的空格
 * 2 + -
 * 3 小数点.(只考虑int)
 * 4 后面的无关字符
 * 5 是否考虑科学计数法(不考虑)
 * 6 越界 INT_MAX INT_MIN
 ***/
class Solution {
public:
    int atoi(const char *str) {
        if (NULL == str)
            return 0;
        
        while (*str == ' ')  // skip the space in head
            ++str;
        
        bool bneg = false;   // + -
        if ('-' == *str)
        {
            bneg = true;
            ++str;
        }
        else if ('+' == *str)
            ++str;
        
        long long num = 0;
        while (isdigit(*str))  // str 2 int
        {
            num = num * 10 + (int)(*str - '0');
            ++str;
        }
        
        if (bneg)
            num = -num;
        
        if (num > INT_MAX)
            num = INT_MAX;
        else if (num < INT_MIN)
            num = INT_MIN;
        
        return num;
    }
};