/***
 * 模拟螺旋操作
 * 设置上下左右四个边界
 ***/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> vnum;
        if (matrix.empty())
            return vnum;
        
        int minx = 0;
        int miny = 0;
        int maxx = matrix[0].size() - 1;
        int maxy = matrix.size() - 1;
        
        while (true)
        {
            // left -> right
            for (int j = minx; j <= maxx; ++j)
                vnum.push_back(matrix[miny][j]);
            if (++miny > maxy)  // miny +1
                break;
            
            // up -> down
            for (int i = miny; i <= maxy; ++i)
                vnum.push_back(matrix[i][maxx]);
            if (--maxx < minx)
                break;
            
            // right -> left
            for (int j = maxx; j >= minx; --j)
                vnum.push_back(matrix[maxy][j]);
            if (--maxy < miny)
                break;
            
            // down -> up
            for (int i = maxy; i >= miny; --i)
                vnum.push_back(matrix[i][minx]);
            if (++minx > maxx)
                break;
        }
        return vnum;
    }
};