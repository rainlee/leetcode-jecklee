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