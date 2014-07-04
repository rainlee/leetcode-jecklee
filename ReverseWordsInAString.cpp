/***
 * ���η�ת
 * ��һ�������ַ�������
 * �ڶ����Կո�ָ���ÿһ�η���
 * ע�⣺
 * 1 û�пո�
 * 2 ��β�пո���Ҫȥ��
 * 3 ��������ո�ֻ����һ��
 * Ϊ���㴦�����һ�Σ���һ��ת��������һ���ո񣬴���������ȥ��
 ***/
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