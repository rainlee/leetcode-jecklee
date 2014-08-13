/***
 * ��1���������� һ������ת
 * ��ʱ�뿽�����߳�Ϊlen��ÿ���߿�������Ϊlen-1
 * ʱ�临�Ӷ�O(n)
 ***/
/*
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
            
        const int n = matrix.size();
        for (int i = 0; i < n/2; ++i)
        {
            int len = n - 2*i;   // side length
            int k = i + len - 1; // rightest of the side
            for (int j = 0; j < len - 1; ++j)  // [0, len-1)
            {
                int tmp = matrix[i][i+j];   // copy in counterclockwise
                matrix[i][i+j] = matrix[k-j][i];
                matrix[k-j][i] = matrix[k][k-j];
                matrix[k][k-j] = matrix[i+j][k];
                matrix[i+j][k] = tmp;
            }
        }
        return;
    }
};
*/

/***
 * ��2�����η�ת
 * ���ظ��Խ��߷�ת������ˮƽ���߷�ת
 * ʱ�临�Ӷ�O(n)
 ***/
/*
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
            
        const int n = matrix.size();
        
        // rotate based on vice diagonal
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n-i; ++j)
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
        
        // rotate based on horizontal midline
        for (int i = 0; i < n/2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n-i-1][j]);
        return;
    }
};
*/

/***
 * ��2�����η�ת
 * ����ˮƽ���߷�ת���������Խ��߷�ת
 * ʱ�临�Ӷ�O(n)
 ***/
/*
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
            
        const int n = matrix.size();
        
        // rotate based on horizontal midline
        for (int i = 0; i < n/2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n-i-1][j]);
        
        // rotate based on main diagonal
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
        return;
    }
};
*/

// �����·�ת���������Խ��߷�ת
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        
        const int n = matrix.size();
        for (int i = 0; i < n/2; ++i)
            matrix[i].swap(matrix[n-i-1]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
        return;
    }
};