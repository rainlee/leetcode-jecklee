/***
 * 同Spiral Matrix模拟
 ***/
/*
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > vvmatrix(n, vector<int>(n));
        if (0 == n)
            return vvmatrix;
        
        int minx = 0;
        int miny = 0;
        int maxx = n - 1;
        int maxy = n - 1;
        int num = 1;        // value, will increase
        while (true)
        {
            // left -> right
            for (int j = minx; j <= maxx; ++j)
                vvmatrix[miny][j] = num++;
            if (++miny > maxy)
                break;
            
            // up -> down
            for (int i = miny; i <= maxx; ++i)
                vvmatrix[i][maxx] = num++;
            if (--maxx < minx)
                break;
            
            // right -> left
            for (int j = maxx; j >= minx; --j)
                vvmatrix[maxy][j] = num++;
            if (--maxy < miny)
                break;
            
            // down -> up
            for (int i = maxy; i >= miny; --i)
                vvmatrix[i][minx] = num++;
            if (++minx > maxx)
                break;
        }
        return vvmatrix;
    }
};
*/

/***
 * 法2：同样是模拟
 * 由于是n*n的边界的设置可以简化
 * 每次一行一列只访问0 ~ n-2
 * 一圈之后，low++ high++
 ***/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > vvmatrix(n, vector<int>(n));
        if (0 == n)
            return vvmatrix;
        
        int low = 0;
        int high = n - 1;
        int num = 1;
        while (low < high)
        {
            for (int j = low; j < high; ++j)
                vvmatrix[low][j] = num++;
            for (int i = low; i < high; ++i)
                vvmatrix[i][high] = num++;
            for (int j = high; j > low; --j)
                vvmatrix[high][j] = num++;
            for (int i = high; i > low; --i)
                vvmatrix[i][low] = num++;
            
            ++low;
            --high;
        }
        if (low == high)
            vvmatrix[low][high] = num;
        return vvmatrix;
    }
};