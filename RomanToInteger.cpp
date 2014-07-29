/***
 * 4000���»��õ� I V X L C D M ���ڴ��������������ֻ����һ��
 * �������ַ���������s[i] < s[i+1]ʱ����Ҫ��ȥs[i]�������
 * ������������ۼ�
 * ��һ��map��¼�������ֵ�int��ӳ���
 ***/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> r2iMap;  // roman to int
        r2iMap['I'] = 1;
        r2iMap['V'] = 5;
        r2iMap['X'] = 10;
        r2iMap['L'] = 50;
        r2iMap['C'] = 100;
        r2iMap['D'] = 500;
        r2iMap['M'] = 1000;
        
        const int n = s.size();
        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((i < n-1) && (r2iMap[s[i]] < r2iMap[s[i+1]]))
                num -= r2iMap[s[i]];
            else
                num += r2iMap[s[i]];
        }
        return num;
    }
};