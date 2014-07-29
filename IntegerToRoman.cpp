/***
 * 法1：按十进制编码
 * 定义一个十进制数（个十百千）到罗马数字的映射表
 * 从低位到高位逐位转换int
 ***/
/*
class Solution {
public:
    string intToRoman(int num) {
        const string i2rMap[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},  
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},  
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  
            {"", "M", "MM", "MMM", "", "", "", "", "", ""} 
        };
        string sroman;
        int d = 0;  // digit
        while (num)
        {
            sroman = i2rMap[d++][num % 10] + sroman;
            num /= 10;
        }
        return sroman;
    }
};
*/

/***
 * 法2：按罗马数字的进制编码
 * 4000以下会用到 I V X L C D M 放在大数左边相减的最多只能有一个
 * 按照以上进制规律 对 4 9 40等编码
 * 从高位往低位计算
 ***/
class Solution {
public:
    string intToRoman(int num) {
        const int ints[] = {
            1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
        };
        const string romans[] = {
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
        };
        
        string sroman;
        int d = 0;
        while (num)
        {
            int n = num / ints[d];   // how many romans in this digit
            while (n--)
                sroman += romans[d];
            num %= ints[d++];        // d++
        }
        return sroman;
    }
};