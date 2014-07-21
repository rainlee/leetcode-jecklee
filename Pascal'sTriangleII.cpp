/***
 * 滚动数组
 * 从上往下计算到第k行（从第0行开始）
 * row[j] = row[j-1] + row[j]; 右边上一行的数据
 * 用一个数组实现滚动
 * 每一行从后往前计算，防止row[j]被覆盖
 ***/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 1);
        for (int i = 1; i <= rowIndex; ++i)
            for (int j = i-1; j >= 1; --j)     // [0, i]
                row[j] += row[j-1];
        return row;
    }
};