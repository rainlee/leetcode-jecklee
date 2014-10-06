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
 * ��1��ö�ٱ�
 * n����������ϣ����Եõ�n(n+ 1)/2��ֱ�ߣ���ÿһ��ֱ�ߣ�
 * �ж�n�����Ƿ��ڸ�ֱ���ϣ��Ӷ����Եõ�����ֱ���ϵĵ�ĸ�����ѡ����������ֱ�߷��ء�
 * ʱ�临�Ӷ�O(n^3)
 * ע��ֱ�ߴ�ֱx������
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
 * ��2��ö�ٵ�
 * ��һ����������ĵ��������������õ������ֱ�ߵ�������
 * ������֮���б�ʣ�Ȼ�󰴴�С��������б����ͬ����ͬһֱ����
 * ͳ�������ֵ
 * ���о���ĳ���ֱ�ߵ�б�ʿ�����map����������¼ͬһб�ʵ����ֵ
 * ͬʱ ע�⴦���غϵĵ�
 * ʱ�临�Ӷ�O(n^2)
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

// ö�ٴ���ĳ�������ֱ��
// ����map�ˣ�֮������е�б�ʴ�������Ȼ�������ҳ�б����ͬ����
// ʱ�临�Ӷ�O(n^2 * logn) �ռ临�Ӷ�O(n)
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