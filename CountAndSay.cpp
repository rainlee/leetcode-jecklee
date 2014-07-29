/***
 * 模拟
 * 循环n次，数出连续的数字下一个字符串先存个数再存数字
 ***/
/*
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0)
            return "";
        
        string spre = "1";
        while (--n)
        {
            string scur;
            int i = 0;
            while (i < spre.size())
            {
                char c = spre[i];
                int j = i + 1;
                while ((j < spre.size()) && (spre[j] == c))
                    ++j;
                scur += to_string(j - i) + c;
                i = j;
            }
            spre = scur;
        }
        return spre;
    }
};
*/

/***
 * 法2：同法1，另外一种itos的方法
 ***/
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0)
            return "";
        
        string spre = "1";
        while (--n)
        {
            stringstream scur;
            int i = 0;
            while (i < spre.size())
            {
                char c = spre[i];
                int j = i + 1;
                while ((j < spre.size()) && (spre[j] == c))
                    ++j;
                scur << (j - i) << c;
                i = j;
            }
            scur >> spre;
        }
        return spre;
    }
};