/***
 * ��1����ȡ���λ�����������м��
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
 * ��2����ת���֣��ȽϺ�ԭ���Ƿ����
 * ������������⣬�������Ļ��϶����ǻ��ĵģ����Բ�����
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