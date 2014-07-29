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
 * ��ǰ�����ڲ����ͬʱ����merge��ϸ�ڴ���
 ***/
/*
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> vret;
        if (intervals.empty())
        {
            vret.push_back(newInterval);
            return vret;
        }
        
        bool binsert = false;  // whether newIntv inserted
        Interval cur;
        int i = 0;
        if (newInterval.start < intervals[0].start)
        {
            binsert = true;
            cur = newInterval;
        }
        else
        {
            cur = intervals[0];
            ++i;
        }
        
        while (i < intervals.size())
        {
            if (!binsert && (cur.end >= newInterval.start))
            {
                cur.end = max(cur.end, newInterval.end);   // merge newInterval
                binsert = true;
            }
            if (cur.end >= intervals[i].start)
            {
                cur.end = max(cur.end, intervals[i].end);  // merge
                ++i;
            }
            else
            {
                vret.push_back(cur);
                if (!binsert && (newInterval.start < intervals[i].start)) // insert
                {
                    binsert = true;
                    cur = newInterval;   // i stays still
                }
                else
                    cur = intervals[i++];
            }
        }
        if (!binsert && (cur.end >= newInterval.start)) // caution!!!
        {
            cur.end = max(cur.end, newInterval.end);   // merge newInterval
            binsert = true;
        }
        vret.push_back(cur);  // last interval
        if (!binsert)
            vret.push_back(newInterval);
            
        return vret;
    }
};
*/

/***
 * ��2����1�����˱����intervals�໥���ǵ����
 * ���intervals���໥���ǣ��������������
 * �ҵ�newInterval�Ĳ�������Ϳ����ˣ�������Ҫmerge��
 ***/
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> vret;
        vector<Interval>::iterator it = intervals.begin();
        while (it != intervals.end())
        {
            if (newInterval.end < it->start)  // insert
            {
                vret.push_back(newInterval);
                vret.insert(vret.end(), it, intervals.end());
                return vret;
            }
            else if (newInterval.start > it->end)
                vret.push_back(*it++);
            else                              // merge
            {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                ++it;
            }
        }
        vret.push_back(newInterval);  // havent insert yet
        return vret;
    }
};