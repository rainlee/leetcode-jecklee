/***
 * ��������
 * �������¼��㵽��k�У��ӵ�0�п�ʼ��
 * row[j] = row[j-1] + row[j]; �ұ���һ�е�����
 * ��һ������ʵ�ֹ���
 * ÿһ�дӺ���ǰ���㣬��ֹrow[j]������
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