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
 * 递归，同Regular Expression Matching 
 * 注意这里的'*'是通配符，和前一个元素无关
 * 递归超时……
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
 * 法2：迭代 + 回溯
 * 匹配*s *p，若匹配，则++s ++p
 * 若不匹配，则检查p之前是否有'*'
 * 是否有*需要记录,遇到*就记录当前*的位置和匹配到的s的位置
 * 然后从*的下一位置和记录的s的下一位置（sbackup每次往后移动一位）匹配（回溯）
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