/***
 * 从左往右遍历，统计字符串的长度，两个词中间至少一个空格
 * 当下一个词加进来后超过L，则不加入
 * 假设有k个词，则计算出空格数 cnt = L - k个词的长度，共有k-1个隔断
 * 每个隔断平均 avrg = cnt / (k-1) 个空格，不能整除的情况 还剩extra = cnt % (k-1)个
 * 不能整除的情况下，每个间隔添加avrg+1个空格(--extra)，直到extra = 0 添加完
 * 注意：最后一行和只有一个单词的行都是左对齐
 ***/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> vret;
        
        const int n = words.size();
        int i = 0;
        while (i < n)
        {
            // expand line
            int len = words[i].size();  // get first word
            int j = i + 1;
            while ((j < n) && ((len + words[j].size() + j-i) <= L) )  // cur len + next word + spaces(at least one)
                len += words[j++].size();   // add one word;
            
            // connect words for a line
            bool isLastLine = (j == n);   // special case
            bool isOneWord = (j-i == 1);
            
            int avrg = (isLastLine || isOneWord) ? 1 : (L-len) / (j-i-1);  // avrg spaces for a interval
            int extra = (isLastLine || isOneWord) ? 0 : (L-len) % (j-i-1); // extra spaces, will be assigned on the right
            
            string sline(words[i]);
            for (int k = i + 1; k < j; ++k)
            {
                sline.append((extra > 0) ? avrg+1 : avrg, ' ');  // spaces: avrg + extra(1)
                sline.append(words[k]);
                --extra;
            }
            sline.append(L - sline.size(), ' ');   // left spaces for left-justified
            
            vret.push_back(sline);  // save sline
            
            i = j;   // caution: move one!!!
        }
        return vret;
    }
};