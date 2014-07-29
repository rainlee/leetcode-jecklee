/***
 * 4000以下会用到 I V X L C D M 放在大数左边相减的最多只能有一个
 * 当罗马字符代表数字s[i] < s[i+1]时，需要减去s[i]代表的数
 * 其他情况都是累加
 * 用一个map记录罗马数字到int的映射表
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