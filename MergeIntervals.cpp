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
 * 先对区间按起点升序排序
 * 然后从前往后归并
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