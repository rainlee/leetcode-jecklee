/***
 * ��1������Ƚ�
 * ��0��ʼ����ÿ��λ�ã��Ƚ����е��ַ�����ֱ������һ����ƥ��
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
 * ��2������Ƚ�
 * �Ե�һ���ַ���Ϊ��׼��ÿһ�ж��͵�һ�бȽϣ�������С����ǰ׺�ĳ���
 * ���ַ������Ӷȶ���O(��n)������2���б������ٶȸ���
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