/***
 * 大数乘法
 * 第i位 和 第j位 相乘的结果放在第 i+j位
 * 注意进位
 * string的num[0]是最高位
 * 相乘的结果放在vector，个位放在第0位
 * 注意去掉结果最高位多余的0
 ***/
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if ((0 == len1) || (0 == len2))
            return "";
        if ( ((1 == len1) && ('0' == num1[0])) ||
             ((1 == len2) && ('0' == num2[0])) )
            return "0";
        
        vector<int> vmul(len1+len2, 0);  // most units len1+len2
        for (int i = len1-1; i >= 0; --i)  // len1-1 ~ 0
        {
            for (int j = len2-1; j >= 0; --j)
            {
                int i2 = len1 - i - 1;  // uints ~ highest order digit
                int j2 = len2 - j - 1;
                int imul = i2 + j2;
                
                int tmpmul = (num1[i] - '0') * (num2[j] - '0');
                int tmpsum = vmul[imul] + tmpmul;
                vmul[imul] = tmpsum % 10;         // update imul
                vmul[imul+1] += tmpsum / 10;      // carry
            }
        }
        
        // vmul 0 ~ len-1, uints ~ highest digit
        int ihigh = vmul.size() - 1;
        while (0 == vmul[ihigh])    // remove the redundant 0 in highest digit
            --ihigh;
        
        string smul("");
        for (int i = ihigh; i >= 0; --i)
            smul += (char)(vmul[i] + '0');
        
        return smul;
    }
};