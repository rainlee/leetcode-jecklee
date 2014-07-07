/***
 * 从右上角开始查找
 * == target, 找到
 * < target, 去掉最右一列
 * > target, 去掉最上面一行
 ***/
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (0 == matrix.size())
            return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int minRow = 0;
        int maxCol = m-1;
        while ((minRow < n) && (maxCol >= 0))
        {
            if (matrix[minRow][maxCol] == target)
                return true;
            else if (matrix[minRow][maxCol] < target)
                ++minRow;
            else
                --maxCol;
        }
        return false;
    }
};
*/

/***
 * 以上算法适用于行从左到右升序，列从上到下升序的矩阵，并不要求下一行的第一个比上一行最后一个大
 * 法2：同样行列扫描，分段查找，二分查找
 * 先对列进行二分，找到在段（行）
 * 再对行进行二分，找到target
 ***/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (0 == matrix.size())
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        
        // bin search col (m-1)
        int low = 0;
        int high = n-1;
        int i = 0;
        int j = m-1;
        while (low <= high)
        {
            i = low + (high-low)/2;
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                low = i + 1;
            else
                high = i - 1;
        }
        
        if (low > n-1)      // not found
            return false;
        
        // bin search row (low)  a[low] > target, a[high] < target
        i = low;       // search this row
        j = 0;
        low = 0;
        high = m - 2;  // m-1 has been checked
        while (low <= high)
        {
            j = low + (high-low)/2;
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                low = j + 1;
            else
                high = j - 1;
        }
        return false;
    }
};