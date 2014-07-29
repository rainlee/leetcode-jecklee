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
 ***/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c = 1;  // carry, plus one
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it)
        {
            int d = *it + c;
            c = d / 10;
            *it = d % 10;
        }
        if (c)
            digits.insert(digits.begin(), c);
        return digits;
    }
};