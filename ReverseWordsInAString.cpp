/***
 * 两次翻转
 * 第一次整个字符串反序
 * 第二次以空格分隔，每一段反序
 * 注意：
 * 1 没有空格
 * 2 首尾有空格，需要去掉
 * 3 多个连续空格，只保留一个
 * 为方便处理最后一段，第一翻转后再最后加一个空格，处理完了再去掉
 ***/
/*
class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() == 0)
            return;
        
        // reverse the whole words
        reverseWord(s, 0, s.size()-1);
        
        // remove the multiple spaces
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                int j = i;
                while (s[++j] == ' ') ;
                s.erase(i + 1, j - i - 1);
            }
        }
        
        // remove the leading space, keep the trailing space
        if (s[0] == ' ')
            s.erase(s.begin());
        if (s[s.size()-1] != ' ')
            s += " ";
        
        // reverse each segment
        int start = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                reverseWord(s, start, i-1);
                start = ++i;
            }
        }
        //reverseWord(s, start, s.size()-1);  // the last segment
        s.erase(s.size()-1, 1);   // remove trailing space
        
        return;
    }
private:
    void reverseWord(string &s, int low, int high)
    {
        while (low < high)
            swap(s[low++], s[high--]);
    }
};
*/

/***
 * 法2：用另外一个字符串来存变换后的结果
 * 从前往后同样按空格分隔，将一个word直接添加到结果串的头
 * 这样处理空格的逻辑更简单
 * 时间复杂度O(n) 空间复杂度O(n)
 * 注意word之间添加空格
 * 法3：以上方法从后往前
 ***/
class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty())
            return;
        
        string sret;
        int i = 0;
        while (i < s.size())
        {
            while ((i < s.size()) && (' ' == s[i]))
                ++i;
            if (i < s.size())
            {
                int start = i;
                while ((i < s.size()) && (' ' != s[i]))
                    ++i;
                if (!sret.empty())
                    sret = " " + sret;
                sret = s.substr(start, i-start) + sret;
            }
        }
        s = sret;
        return;
    }
};