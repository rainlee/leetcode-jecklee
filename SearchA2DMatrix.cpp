/***
 * �����Ͻǿ�ʼ����
 * == target, �ҵ�
 * < target, ȥ������һ��
 * > target, ȥ��������һ��
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
 * �����㷨�������д����������д��ϵ�������ľ��󣬲���Ҫ����һ�еĵ�һ������һ�����һ����
 * ��2��ͬ������ɨ�裬�ֶβ��ң����ֲ���
 * �ȶ��н��ж��֣��ҵ��ڶΣ��У�
 * �ٶ��н��ж��֣��ҵ�target
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