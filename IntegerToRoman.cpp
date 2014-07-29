/***
 * ��1����ʮ���Ʊ���
 * ����һ��ʮ����������ʮ��ǧ�����������ֵ�ӳ���
 * �ӵ�λ����λ��λת��int
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
 * ��2�����������ֵĽ��Ʊ���
 * 4000���»��õ� I V X L C D M ���ڴ��������������ֻ����һ��
 * �������Ͻ��ƹ��� �� 4 9 40�ȱ���
 * �Ӹ�λ����λ����
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