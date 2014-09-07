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
 * ��1�������򣬺������ʱ�临�Ӷ�O(nlogn)
 * ��2���ռ任ȡʱ�䣬����hash��ֻ�豣��key������Ҫ�������ظ�Ԫ��ֻ��һ�ξͿ����ˣ�
 *      �ӵ�һ������ʼ����ǰ��ͺ�����������߼���������������õ�����󳤶ȣ����������������ֵ
 *      �Ż����ҹ���������ɾ�������������ظ����ң���Ϊ�������ε����������ʹ���
 ***/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> smap;
        for (int i = 0; i < num.size(); ++i)  // create hash map
            smap.insert(num[i]);
        
        int maxl = INT_MIN;
        for (int i = 0; (i < num.size()) && !smap.empty(); ++i)
        {
            int left = num[i];
            while (smap.find(--left) != smap.end())  // expend to left
                smap.erase(left);  // erase visited node
            int right = num[i];
            while (smap.find(++right) != smap.end())
                smap.erase(right);
            maxl = max(maxl, right-left+1);
        }
        return maxl;
    }
};

// ��set�Զ�����Ȼ�����set��ͳ��һ�飬��¼���ֵ
// �����Ӷ�O(nlogn)
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() < 2)
            return num.size();
        set<int> snum;
        for (int i = 0; i < num.size(); ++i)
            snum.insert(num[i]);
        
        int maxl = 1;
        int cnt = 1;
        set<int>::iterator it = snum.begin();
        int last = *it;
        for (++it; it != snum.end(); ++it)
        {
            if (*it == last + 1)
                ++cnt;
            else
            {
                maxl = max(maxl, cnt);
                cnt = 1;
            }
            last = *it;
        }
        maxl = max(maxl, cnt);  // last seg
        
        return maxl;
    }
};