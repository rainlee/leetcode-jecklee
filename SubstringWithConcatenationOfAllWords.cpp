/***
 * ͬLongest Substring Without Repeating Characters
 * ��Ŀ��Ҫ��S�ҵ�����L�������Ӵ�����L��Ԫ����ɵ��Ӵ�����������
 * ˫ָ�� + hash ά��һ���ƶ�����
 * ����S��ÿ��ǰ��L�е��ַ������ȣ��ȳ�����ö�����
 * ���Llen�ĳ��ȣ�����Ƿ���L���Ӵ�
 * ��һ��map�����Ѿ����ֹ���L�ͳ��ִ����������ظ���
 * ʱ�临�Ӷ�O(n*len)
 ***/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> vind;
        if ((0 == S.size()) || (0 == L.size()))
            return vind;
            
        int wlen = L[0].size();
        int Llen = wlen * L.size();
        
        if (S.size() < Llen)
            return vind;
        
        map<string, int> mdicL;
        for (int i = 0; i < L.size(); ++i)
            ++mdicL[L[i]];
        
        for (int i = 0; i <= S.size() - Llen; ++i)  // foreach the start of window; mind the right bound
        {
            map<string, int> mcntm;  // count matched
            int j;
            for (j = 0; j < Llen; j += wlen)  // wlen * wnum
            {
                string word = S.substr(i + j, wlen);
                if (mdicL.find(word) == mdicL.end())   // word not in L
                    break;
                    
                if (++mcntm[word] > mdicL[word])  // record the word; if word not in L, break
                    break;
            }
            if (j >= Llen)  // found
                vind.push_back(i);
        }
        return vind;
    }
};