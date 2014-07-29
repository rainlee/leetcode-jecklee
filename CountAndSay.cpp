/***
 * ģ��
 * ѭ��n�Σ�����������������һ���ַ����ȴ�����ٴ�����
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
 * ��2��ͬ��1������һ��itos�ķ���
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