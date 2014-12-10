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
 * 法1：
 * 每次和左右比较，注意处理收尾
 * 复杂度O(n) 比较次数2n
 ***/
/*
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() == 1) return 0;
        for (int i = 0; i < num.size(); ++i)
            if (((i == 0) && (num[i] > num[i+1])) || 
                ((i == num.size()-1) && (num[i] > num[i-1])) || 
                ((num[i] > num[i-1]) && (num[i] > num[i+1])))
                return i;
        return -1;
    }
};
*/

/***
 * 法2：
 * 找到第一段升序的最高点，只用和后一个数比较
 * 复杂度O(n) 比较次数n
 ***/
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.empty()) return -1;
        int i = 0;
        while ((i < num.size()-1) && (num[i] < num[i+1]))
            ++i;
        return i;
    }
};