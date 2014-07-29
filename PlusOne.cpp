/***
 * �����ӷ�
 * vector�����Ҵ���Ǹ�λ����λ
 * �ӵ�λ����λ���д���
 ***/
/*
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> vret;
        int c = 1;  // carry, plus one
        int d = 0;
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it)
        {
            d = *it + c;
            c = d / 10;
            d = d % 10;
            vret.insert(vret.begin(), d);
        }
        if (c)
            vret.insert(vret.begin(), c);
        return vret;
    }
};
*/

/***
 * ��2������digits���飬ֱ���޸�ԭ����
 ***/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c = 1;  // carry, plus one
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it)
        {
            int d = *it + c;
            c = d / 10;
            *it = d % 10;
        }
        if (c)
            digits.insert(digits.begin(), c);
        return digits;
    }
};