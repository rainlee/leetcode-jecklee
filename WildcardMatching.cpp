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
 * �ݹ飬ͬRegular Expression Matching 
 * ע�������'*'��ͨ�������ǰһ��Ԫ���޹�
 * �ݹ鳬ʱ����
 ***/
/*
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if ('\0' == *p)
            return ('\0' == *s);
        if ('\0' == *s)
            return ('*' == *p) && ('\0' == *(p+1));
        
        if (*p == '*')
        {
            while (*p == '*') ++p;   // skip continous '*'
            return isMatch(s+1, p-1) || isMatch(s, p);  // use '*' || jump '*'
        }
        else if (('\0' != *s) && ((*p == *s) || ('?' == *p)))
            return isMatch(s+1, p+1);
        else
            return false;
    }
};
*/

/***
 * ��2������ + ����
 * ƥ��*s *p����ƥ�䣬��++s ++p
 * ����ƥ�䣬����p֮ǰ�Ƿ���'*'
 * �Ƿ���*��Ҫ��¼,����*�ͼ�¼��ǰ*��λ�ú�ƥ�䵽��s��λ��
 * Ȼ���*����һλ�úͼ�¼��s����һλ�ã�sbackupÿ�������ƶ�һλ��ƥ�䣨���ݣ�
 ***/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *sbackup = NULL;
        const char *pbackup = NULL;
        while (*s != '\0')
        {
            if ((*p == '?') || (*p == *s))  // match
            {
                ++s;
                ++p;
            }
            else if (*p == '*')  // mark the pos of '*'
            {
                while (*p == '*')  // skip continous '*'
                    ++p;
                if (*p == '\0')    // end with '*'
                    return true;
                
                sbackup = s;
                pbackup = p;
            }
            else   // not match, back up
            {
                if (!sbackup)
                    return false;
                
                s = ++sbackup;   // '*' matches (*sbackup), move to next s
                p = pbackup;
            }
        }
        while (*p == '*')  // skip '*'
            ++p;
        return (*p == '\0');
    }
};