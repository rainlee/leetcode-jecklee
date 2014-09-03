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
 * 大数加法
 * vector从左到右存的是高位到低位
 * 从低位到高位进行处理
 ***/
/*
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> vret;
        int c = 1;  // carry, plus one
        int d = 0;
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it)
        {
            d = *it + c;
            c = d / 10;
            d = d % 10;
            vret.insert(vret.begin(), d);
        }
        if (c)
            vret.insert(vret.begin(), c);
        return vret;
    }
};
*/

/***
 * 法2：复用digits数组，直接修改原数组
 * 优化：c=0 不再有进位时，可以停止
 ***/
/*
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c = 1;  // carry, plus one
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it)
        {
            int d = *it + c;
            c = d / 10;
            *it = d % 10;
            if (0 == c)   // needn't plus
                break;
        }
        if (c)
            digits.insert(digits.begin(), c);
        return digits;
    }
};
*/

/*
// 同2
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty())
            return digits;
        
        int c = 1;
        for (int i = digits.size()-1; i >= 0; --i)
        {
            digits[i] += c;
            c = digits[i] / 10;
            digits[i] %= 10;
            if (0 == c)
                break;
        }
        if (c)
            digits.insert(digits.begin(), c);
        return digits;
    }
};
*/

/***
 * 法3：从后往前，找到第一个不为9的数，将其加1，其后的数全部变为0
 * 例如：12399 + 1 = 12400
 * 注意全9的情况
 ***/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool badded = false;
        for (int i = digits.size()-1; i >= 0; --i)
        {
            if (9 == digits[i])
                digits[i] = 0;
            else
            {
                ++digits[i];
                badded = true;
                break;
            }
        }
        if (!badded)  // all 9
            digits.insert(digits.begin(), 1);
        return digits;
    }
};