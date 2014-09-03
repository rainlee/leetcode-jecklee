/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         God Bless Me     BUG Free Forever
*/
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
 * �Ż���c=0 �����н�λʱ������ֹͣ
 ***/
/*
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c = 1;  // carry, plus one
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it)
        {
            int d = *it + c;
            c = d / 10;
            *it = d % 10;
            if (0 == c)   // needn't plus
                break;
        }
        if (c)
            digits.insert(digits.begin(), c);
        return digits;
    }
};
*/

/*
// ͬ2
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty())
            return digits;
        
        int c = 1;
        for (int i = digits.size()-1; i >= 0; --i)
        {
            digits[i] += c;
            c = digits[i] / 10;
            digits[i] %= 10;
            if (0 == c)
                break;
        }
        if (c)
            digits.insert(digits.begin(), c);
        return digits;
    }
};
*/

/***
 * ��3���Ӻ���ǰ���ҵ���һ����Ϊ9�����������1��������ȫ����Ϊ0
 * ���磺12399 + 1 = 12400
 * ע��ȫ9�����
 ***/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool badded = false;
        for (int i = digits.size()-1; i >= 0; --i)
        {
            if (9 == digits[i])
                digits[i] = 0;
            else
            {
                ++digits[i];
                badded = true;
                break;
            }
        }
        if (!badded)  // all 9
            digits.insert(digits.begin(), 1);
        return digits;
    }
};