/***
 * 从右上角开始查找
 * == target, 找到
 * < target, 去掉最右一列
 * > target, 去掉最上面一行
 * 时间复杂度 O(m+n)
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
 * 时间复杂度 O(logn + logm)
 ***/
/*
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
*/

/***
 * 法3：一次二分查找
 * 将矩阵展开成一维后是个有序数组，直接对其进行查找
 * low = 0, high = m*n - 1, mid = (low+high)/2
 * 将一维的mid转换成二维的横纵坐标
 * y = mid / n, x = mid % n
 * 时间复杂度O(m*n)
 ***/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0;
        int high = m*n - 1;
        while (low <= high)
        {
            int mid = (low & high) + ((low ^ high) >> 1);
            int y = mid / n;   // row
            int x = mid % n;   // col
            if (target == matrix[y][x])
                return true;
            else if (target > matrix[y][x])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};