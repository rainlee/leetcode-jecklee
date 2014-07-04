/***
 * ע�⴦�������������ǰ����
 * 1 ȥ��ǰ�����Ŀո�
 * 2 + -
 * 3 С����.(ֻ����int)
 * 4 ������޹��ַ�
 * 5 �Ƿ��ǿ�ѧ������(������)
 * 6 Խ�� INT_MAX INT_MIN
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