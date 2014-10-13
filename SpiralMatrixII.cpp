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

// 法3：如果只要求打印，不用保存，以下算法可以达到空间O(1)
// 通过坐标(x,y)计算该位置的值
// 首先计算出当前在第几层c
// 然后计算出该层左上角第一个数的大小lefttop
// 得到当前环的边长l
// (x,y)换算成相对于lefttop的坐标(i,j)
// 判断在上下左右哪条边上，然后计算
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matrix[i][j] = getNum(i, j, n);
        return matrix;
    }
private:
    int getNum(int x, int y, int n)
    {
        int c = min(min(x, n-x-1), min(y, n-y-1));  // 第几层,从0开始
        int lefttop = 1 + 4*c*(n-c);  // 每层有4*(n-2*c+1)个
        int l = n - 2*c;
        int i = x - c;
        int j = y - c;
        if (i == 0)        // up
            return lefttop + j;
        else if (j == 0)   // left
            return lefttop + 4*(l-1) - i;
        else if (i == l-1) // down
            return lefttop + 3*l - j - 3;  // lefttop + 2*(l-1) + (l-j+1);
        else               // right
            return lefttop + l + i - 1;
    }
};