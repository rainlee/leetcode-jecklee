/***
 * ��1��˳����� O(n)
 ***/
/*
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> vrange(2, -1);
        int end = -1;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (target == A[i])
            {
                ++cnt;
                end = i;
            }
        }
        if (cnt > 0)
        {
            vrange[0] = end - cnt + 1;
            vrange[1] = end;
        }
        return vrange;
    }
};
*/

/***
 * ��2�����ֲ���
 * �ҵ�target��Ȼ����������չ
 * ������A����Ԫ�ض���target�����㷨��O(logn)�˻�ΪO(n)
 ***/
/*
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> vrange(2, -1);
        int low = 0;
        int high = n-1;
        int mid = 0;
        while (low <= high)
        {
            mid = (low & high) + ((low ^ high) >> 1);
            if (target == A[mid])
                break;
            else if (target > A[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (target == A[mid])  // expand
        {
            int start = mid;
            while ((start > 0) && (target == A[start-1]))
                --start;
            int end = mid;
            while ((end < n-1) && (target == A[end+1]))
                ++end;
            vrange[0] = start;
            vrange[1] = end;
        }
        return vrange;
    }
};
*/

/***
 * ��3�����ֲ��ҷֱ��ҳ����±߽�
 * ʱ�临�Ӷ�O(logn)
 ***/
/*
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> vrange(2, -1);
        int left = lowerBound(A, n, target);
        int right = upperBound(A, n, target);
        if (left <= right)
        {
            vrange[0] = left;
            vrange[1] = right;
        }
        return vrange;
    }
private:
    int lowerBound(int A[], int n, int target) {
        int low = 0;
        int high = n-1;
        while (low <= high)
        {
            int mid = (low & high) + ((low ^ high) >> 1);
            if (target > A[mid])
                low = mid + 1;
            else    // <=
                high = mid - 1;
        }
        return low;
    }
    int upperBound(int A[], int n, int target) {
        int low = 0;
        int high = n-1;
        while (low <= high)
        {
            int mid = (low & high) + ((low ^ high) >> 1);
            if (target < A[mid])
                high = mid - 1;
            else    // >=
                low = mid + 1;
        }
        return high;
    }
};
*/

/***
 * ��4��ֱ�ӵ���STL
 * lower_bound upper_bound
 ***/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left = distance(A, lower_bound(A, A+n, target));
        int right = distance(A, prev(upper_bound(A, A+n, target)));
        if (left <= right)
            return vector<int>{left, right};
        else
            return vector<int>{-1, -1};
    }
};