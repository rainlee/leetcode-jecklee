/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
/***
 * 法1：枚举边
 * n个点两两组合，可以得到n(n+ 1)/2条直线，对每一条直线，
 * 判断n个点是否在该直线上，从而可以得到这条直线上的点的个数，选择最大的那条直线返回。
 * 时间复杂度O(n^3)
 * 注意直线垂直x轴的情况
 ***/
/*
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        const int n = points.size();
        if (n < 3)
            return n;
        int maxcnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                bool bvertical = false;
                int a, b, c;
                if (points[i].x == points[j].x)  // x = c
                    bvertical = true;
                else                             // a*x + b*y = c
                {
                    a = points[i].y - points[j].y;
                    b = points[i].x - points[j].x;
                    c = b*points[i].y - a*points[i].x;
                }
                int cnt = 0;
                for (int k = 0; k < n; ++k)      // check each point whether in this line
                    if ( (bvertical && (points[k].x == points[i].x)) ||
                         (!bvertical && (b*points[k].y - a*points[k].x == c)) )
                        ++cnt;
                maxcnt = max(maxcnt, cnt);
            }
        }
        return maxcnt;
    }
};
*/

/***
 * 法2：枚举点
 * 用一个点和其他的点相连，检查包含该点的所有直线的最多点数
 * 求两点之间的斜率，然后按从小到大排序，斜率相同即在同一直线上
 * 统计求最大值
 * 其中经过某点各直线的斜率可以用map存下来，记录同一斜率的最大值
 * 同时 注意处理重合的点
 * 时间复杂度O(n^2)
 ***/
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        const int n = points.size();
        if (n < 3)
            return n;
            
        unordered_map<double, int> kmap;  // slope coefficient - count of lines
        int maxcnt = 0;
        for (int i = 0; i < n; ++i)
        {
            kmap.clear();
            int samepoint = 0;  // same with points[i]
            int maxsal = 1;     // max points in same line, 1 for i
            for (int j = i+1; j < n; ++j) // line (i, j)
            {
                double slope;
                if (points[j].x == points[i].x)
                {
                    slope = std::numeric_limits<double>::infinity();   // x = c
                    if (points[j].y == points[i].y)
                    {
                        ++samepoint;
                        continue;
                    }
                }
                else
                    slope = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                int cnt = 0;
                if (kmap.find(slope) != kmap.end())  // the line has existed
                    cnt = ++kmap[slope];
                else
                {
                    cnt = 2;
                    kmap[slope] = 2;   // init
                }
                maxsal = max(maxsal, cnt);  // max points in same line, pass i
            }
            maxcnt = max(maxcnt, maxsal + samepoint); // max points
        }
        return maxcnt;
    }
};