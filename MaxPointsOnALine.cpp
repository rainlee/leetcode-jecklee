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
        if (points.size() < 3)
            return points.size();
        
        int maxp = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            int samep = 1;     // same with points[i]
            int maxcnt = 0;    // max points in same line
            vector<double> vslope;  // slopes
            for (int j = i+1; j < points.size(); ++j)
            {
                double slope = 0;
                if ((points[j].x == points[i].x) && (points[j].y == points[i].y))
                {
                    ++samep;
                    continue;
                }
                else if (points[j].x == points[i].x)
                    slope = std::numeric_limits<double>::max();
                else
                    slope = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                vslope.push_back(slope);
                maxcnt = max(maxcnt, mslope[slope]);
            }
            maxp = max(maxp, samep + maxcnt);
        }
        return maxp;
    }
};

// 枚举穿过某点的所有直线
// 不用map了，之间把所有的斜率存下来，然后排序，找出斜率相同最大的
// 时间复杂度O(n^2 * logn) 空间复杂度O(n)
const double EPSILON = 0.000001;
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() < 3)
            return points.size();
        
        int maxp = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            int samep = 1;
            int maxcnt = 0;
            vector<double> vslope;  // slope
            for (int j = i+1; j < points.size(); ++j)
            {
                double slope = 0;
                if ((points[j].x == points[i].x) && (points[j].y == points[i].y))
                {
                    ++samep;
                    continue;
                }
                else if (points[j].x == points[i].x)
                    slope = numeric_limits<double>::max();
                else
                    slope = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                vslope.push_back(slope);
            }
            sort(vslope.begin(), vslope.end());
            for (int i = 0, j = 0; i < vslope.size(); i = j)
            {
                while ((j < vslope.size()) && (abs(vslope[j] - vslope[i]) <= EPSILON))
                    ++j;
                maxcnt = max(maxcnt, j - i);
            }
            maxp = max(maxp, samep + maxcnt);
        }
        return maxp;
    }
};