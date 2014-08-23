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
 * 递归 + 回溯
 * 由于'*'和前一个元素相关，所以每次判断后一个元素*(p+1)
 * 完全匹配的条件是s p 都到达末尾
 * 若*(p+1) != '*'，则前一个必须匹配（相等或者有'.'）
 *          == '*'，若前一个不匹配，则比较(s, p+2) 跳过p和p+1
 *                            匹配，则比较(s+1, p) 跳过s || (s, p+2) 跳过'*'
 * 注意：'*'匹配前一个元素的0个或多个
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
 * 法2：在法1的基础上 另一种递归
 * 当*(p+1) == '*'，此时看从s[i]开始的子串
 * 假设s[i],s[i+1],...s[i+k]都等于p[j]那么意味着这些都有可能是合适的匹配
 * 那么递归对于剩下的(i,j+2),(i+1,j+2),...,(i+k,j+2)都要尝试（j+2是因为跳过当前和下一个'*'字符）。 
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
 * 法3：另外一种递归逻辑，判断当前元素*p（法1是先判断*(p+1)）
 * 若*p == *s，若*(p+1) != '*'，直接后移，比较(s+1, p+1)
 *                      ==      使用'*'通配 (s+1, p) || 不使用'*' (s, p+2)
 *      !=              !=      false
 *                      ==      跳过 比较(s, p+2)
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