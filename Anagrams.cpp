/***
 * eat tea �ǻ��Ĺ��ʷ���eye�ǻ���
 * ��һ��map��¼���е��ַ����������ȶ��ַ�������
 * map�м�¼���ǻ��Ĺ��ʷ������Ĵʣ��͵�һ�����ֵĴʵ�λ��
 * �����map���ҵ��ַ�������˵���л��Ĺ���
 * ����һ���ʺ͵�ǰ�ʴ�����
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