/***
 * 法1：获取最高位，从两边向中间比
 ***/
/*
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)    // neg
            return false;
        if (x < 10)
            return true;
        
        int hbase = 1;
        while (x / hbase >= 10)
            hbase *= 10;
        
        while (hbase > 9)
        {
            int low = x % 10;
            int high = x / hbase;
            if (low != high)
                return false;
            
            x = (x % hbase) / 10;
            hbase /= 100;          // two digits
        }
        return true;
    }
};
*/

/***
 * 法2：逆转数字，比较和原数是否相等
 * 存在溢出的问题，如果溢出的话肯定不是回文的，可以不考虑
 ***/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)    // neg
            return false;
        if (x < 10)
            return true;
        
        return (x == reverse(x));
    }
private:
    static int reverse(int x)
    {
        int r = 0;
        
        while (x)
        {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
};