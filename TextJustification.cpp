/***
 * �������ұ�����ͳ���ַ����ĳ��ȣ��������м�����һ���ո�
 * ����һ���ʼӽ����󳬹�L���򲻼���
 * ������k���ʣ��������ո��� cnt = L - k���ʵĳ��ȣ�����k-1������
 * ÿ������ƽ�� avrg = cnt / (k-1) ���ո񣬲������������ ��ʣextra = cnt % (k-1)��
 * ��������������£�ÿ��������avrg+1���ո�(--extra)��ֱ��extra = 0 �����
 * ע�⣺���һ�к�ֻ��һ�����ʵ��ж��������
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