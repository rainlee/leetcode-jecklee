/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         God Bless Me     BUG Free Forever
*/
/***
 * �ݹ� + ����
 * ����'*'��ǰһ��Ԫ����أ�����ÿ���жϺ�һ��Ԫ��*(p+1)
 * ��ȫƥ���������s p ������ĩβ
 * ��*(p+1) != '*'����ǰһ������ƥ�䣨��Ȼ�����'.'��
 *          == '*'����ǰһ����ƥ�䣬��Ƚ�(s, p+2) ����p��p+1
 *                            ƥ�䣬��Ƚ�(s+1, p) ����s || (s, p+2) ����'*'
 * ע�⣺'*'ƥ��ǰһ��Ԫ�ص�0������
 ***/
/*
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if ('\0' == *p)   // the end
            return ('\0' == *s);
        
        if (*(p+1) != '*')
        {
            if (('\0' != *s) && ((*s == *p) || (*p == '.')))
                return isMatch(s+1, p+1);
            else
                return false;
        }
        else
        {
            if (('\0' != *s) && ((*s == *p) || (*p == '.')))
                return isMatch(s+1, p) || isMatch(s, p+2);    // use '*' || jump '*'
            else
                return isMatch(s, p+2);  // jump '*'
        }
    }
};
*/

/***
 * ��2���ڷ�1�Ļ����� ��һ�ֵݹ�
 * ��*(p+1) == '*'����ʱ����s[i]��ʼ���Ӵ�
 * ����s[i],s[i+1],...s[i+k]������p[j]��ô��ζ����Щ���п����Ǻ��ʵ�ƥ��
 * ��ô�ݹ����ʣ�µ�(i,j+2),(i+1,j+2),...,(i+k,j+2)��Ҫ���ԣ�j+2����Ϊ������ǰ����һ��'*'�ַ����� 
 ***/
/*
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if ('\0' == *p)
            return ('\0' == *s);
        
        if ('*' != *(p+1))
        {
            if (('\0' != *s) && ((*s == *p) || (*p == '.')))
                return isMatch(s+1, p+1);
            else
                return false;
        }
        else
        {
            while (('\0' != *s) && ((*s == *p) || (*p == '.')))
            {
                if (isMatch(s, p+2))  // jump '*'
                    return true;
                ++s;                  // next s
            }
            return isMatch(s, p+2);   // pre not match, have to jump '*'
        }
    }
};
*/

/***
 * ��3������һ�ֵݹ��߼����жϵ�ǰԪ��*p����1�����ж�*(p+1)��
 * ��*p == *s����*(p+1) != '*'��ֱ�Ӻ��ƣ��Ƚ�(s+1, p+1)
 *                      ==      ʹ��'*'ͨ�� (s+1, p) || ��ʹ��'*' (s, p+2)
 *      !=              !=      false
 *                      ==      ���� �Ƚ�(s, p+2)
 ***/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if ('\0' == *p)
            return ('\0' == *s);
        
        if (('\0' != *s) && ((*p == *s) || ('.' == *p)))
            return (*(p+1) == '*') ? (isMatch(s+1, p) || isMatch(s, p+2)) : // use '*' || not use '*'
                                      isMatch(s+1, p+1);          // match move on
        else
            return (*(p+1) == '*') ? isMatch(s, p+2) : false;     // not use '*'
    }
};