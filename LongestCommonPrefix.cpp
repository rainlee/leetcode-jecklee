/***
 * 法1：纵向比较
 * 从0开始，对每个位置，比较所有的字符串，直到遇到一个不匹配
 ***/
/*
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        
        for (int j = 0; j < strs[0].size(); ++j)   // horizontal 
            for (int i = 1; i < strs.size(); ++i)  // vertical 
                if (strs[0][j] != strs[i][j])   // mismatch
                    return strs[0].substr(0, j);
        return strs[0];   // strs[0] all matched
    }
};
*/

/***
 * 法2：横向比较
 * 以第一个字符串为基准，每一行都和第一行比较，不断缩小公共前缀的长度
 * 两种方法复杂度都是O(∑n)，但法2按行遍历，速度更快
 ***/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        
        int maxl = strs[0].size();
        for (int i = 1; i < strs.size(); ++i)
            for (int j = 0; j < maxl; ++j)
                if (strs[i][j] != strs[0][j])  // wont overflow string::[]
                    maxl = j;
        return strs[0].substr(0, maxl);
    }
};