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
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/***
 * �ȶ����䰴�����������
 * Ȼ���ǰ����鲢
 ***/
bool cmpintv(const Interval &v1, const Interval &v2)
{
    return v1.start < v2.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> vret;
        if (intervals.empty())
            return vret;
        
        sort(intervals.begin(), intervals.end(), cmpintv);
        
        Interval cur = intervals[0];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (cur.end >= intervals[i].start)  // cross over
                cur.end = max(cur.end, intervals[i].end);
            else
            {
                vret.push_back(cur);
                cur = intervals[i];
            }
        }
        vret.push_back(cur);  // caution: the last interval!!!
        return vret;
    }
};

// ֱ����ԭintervals�����Ͻ���merge
// ����ǰ�����last���룬����µ�ǰ����Ϊlast
// �����������ཻ���ϲ���ȡend�ϴ�ֵ��ɾ����ǰ����
bool cmpIntv(const Interval &i1, const Interval &i2)
{
    return (i1.start < i2.start);
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2)
            return intervals;
        
        sort(intervals.begin(), intervals.end(), cmpIntv);
        
        int start = intervals[0].start;
        int end = intervals[0].end;
        for (int i = 1; i < intervals.size(); )
        {
            if (end < intervals[i].start)
            {
                start = intervals[i].start;
                end = intervals[i].end;
                ++i;   // move on
            }
            else
            {
                if (end < intervals[i].end)
                {
                    end = intervals[i].end;
                    intervals[i-1].end = end;
                }
                // else end stays still
                intervals.erase(intervals.begin() + i);
            }
        }
        return intervals;
    }
};