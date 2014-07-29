/***
 * �д�����״̬���㶨��Ĥ�ݡ��� https://github.com/rainlee/LeetCode-1/blob/master/ValidNumber.h
 * �����ַ����еļ�������Ԫ�أ��ֱ��ñ���ȥ���
 * space, �ո�ֻ���ڿ�ͷ�ͽ�β�пո�ȥ����ͷ�Ŀո�
 * neg, �����ţ����ܳ����ڿ�ͷ����e����
 * num, ���֣�����Ҫ������
 * dot, С���㣬ֻ����һ����������e��
 * exp, e��ѧ��������ֻ����һ����ǰ����������֣�������������֣�������+ -��
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