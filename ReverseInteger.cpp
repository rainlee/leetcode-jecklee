/***
 * 从低位到高位处理
 * 翻转int可能会溢出，最后检测一下
 ***/
class Solution {
public:
    int reverse(int x) {
        long long r = 0;
        
        while (x)
        {
            r = r * 10 + x % 10;
            x /= 10;
        }
        
        assert((r >= INT_MIN) && (r <= INT_MAX));
        return r;
    }
};