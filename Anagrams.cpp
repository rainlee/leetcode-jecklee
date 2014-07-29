/***
 * eat tea 是回文构词法，eye是回文
 * 用一个map记录所有的字符串，可以先对字符串排序
 * map中记录的是回文构词法排序后的词，和第一个出现的词的位置
 * 如果在map中找到字符串，则说明有回文构词
 * 将第一个词和当前词存入结果
 ***/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> vanag;
        unordered_map<string, int> smap;  // string - index
        for (int i = 0; i < strs.size(); ++i)
        {
            string stmp = strs[i];
            sort(stmp.begin(), stmp.end());  // sort first
            if (smap.find(stmp) == smap.end())
                smap[stmp] = i;
            else
            {
                if (smap[stmp] != -1)  // save the first string
                {
                    vanag.push_back(strs[smap[stmp]]);
                    smap[stmp] = -1;   // mark
                }
                vanag.push_back(strs[i]);
            }
        }
        return vanag;
    }
};