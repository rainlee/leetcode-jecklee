/***
 * 从后向前，按位相加
 ***/
class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;   // carry
        while ((i >= 0) || (j >= 0) || c)
        {
            int numa = (i >= 0) ? (a[i--] - '0') : 0;
            int numb = (j >= 0) ? (b[j--] - '0') : 0;
            int num = numa + numb + c;
            c = num >> 1;
            num &= 0x1;
            sum = (char)(num + '0') + sum;  // low digit in low bit
        }
        return sum;
    }
};