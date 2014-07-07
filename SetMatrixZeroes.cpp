/***
 * �����������飬���ÿ��ÿ���Ƿ����0
 * �ȱ���һ�飬�ٸ��ݱ����������0
 * ʱ�临�Ӷ�O(m*n), �ռ临�Ӷ�O(m+n)
 ***/
/*
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (0 == matrix.size())
            return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<bool> vrow(m, false);
        vector<bool> vcol(n, false);
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (0 == matrix[i][j])
                {
                    vrow[i] = true;
                    vcol[j] = true;
                }
            }
        }
        
        for (int i = 0; i < m; ++i)
            if (vrow[i])
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
        
        for (int j = 0; j < n; ++j)
            if (vcol[j])
                for (int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
        
        return;
    }
};
*/

/***
 * ��2��˼·ͬ��1������matrix�ĵ�һ�� ��һ�У���Ϊ�������
 * ������Ҫ������������ǵ�һ�е�һ�� �Ƿ���0
 * ʱ�临�Ӷ�O(m*n), �ռ临�Ӷ�O(1)
 ***/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (0 == matrix.size())
            return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool brow0 = false;  // first row has 0 or not
        bool bcol0 = false;  // first col has 0 or not
        
        for (int j = 0; j < n; ++j)  // first row
        {
            if (0 == matrix[0][j])
            {
                brow0 = true;
                break;
            }
        }
        for (int i = 0; i < m; ++i)  // first col
        {
            if (0 == matrix[i][0])
            {
                bcol0 = true;
                break;
            }
        }
        
        for (int i = 1; i < m; ++i) // other rows and cols
            for (int j = 1; j < n; ++j)
                if (0 == matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
        
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if ((0 == matrix[0][j]) || (0 == matrix[i][0]))  // first row || first col
                    matrix[i][j] = 0;
        
        if (brow0)
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        
        if (bcol0)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        
        return;
    }
};