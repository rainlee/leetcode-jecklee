/***
 * ��1������һ�飬O(n)
 ***/
/*
class Solution {
public:
    int findMin(vector<int> &num) {
        int minv = INT_MAX;
        for (int i = 0; i < num.size(); ++i)
            minv = min(minv, num[i]);
        return minv;
    }
};
*/

/***
 * ��2�����ֲ��ң������
 * ��ǰ��Ⱥ�һ����󣬺�һ����������
 ***/
class Solution {
public:
    int findMin(vector<int> &num) {
        const int n = num.size();
        if (n == 0) return INT_MAX;
        if (n == 1) return num[0];
        if (num[0] < num[n-1]) return num[0];
        
        int low = 0;
        int high = n-1;
        while (low <= high)
        {
            int mid = (low&high) + ((low^high) >> 1);
            if (num[mid] > num[mid+1])
                return num[mid+1];
            else if (num[mid] >= num[low])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return INT_MAX;
    }
};