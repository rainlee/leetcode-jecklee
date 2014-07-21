/***
 * ��1��̰��
 * ÿ�ζ���¼�ܹ�iλ���ܵ������Զ���룬
 * ������n-1�����߲��ܼ���ǰ��ʱ��ֹͣ
 ***/
/*
class Solution {
public:
    bool canJump(int A[], int n) {
        int maxrb = 0;  // max right bound
        for (int i = 0; i < n; ++i)
        {
            maxrb = max(maxrb, A[i]);  // can move maxrb steps
            if (maxrb > 0)  // move on
                --maxrb;
            else            // stop here
                return (i == n-1);     // if reach the end
        }
        return true;  // reach the end
    }
};
*/

/***
 * ��2��̰��
 * �������ұ�������¼��0��ʼ�ܵ������Զλ��
 * ����ܳ���n-1������Ե���
 ***/
/*
class Solution {
public:
    bool canJump(int A[], int n) {
        int maxrb = 0;
        for (int i = 0; (i <= maxrb) && (maxrb < n); ++i)  // i <= maxrb, can reach
            maxrb = max(maxrb, i + A[i]);
        return (maxrb >= n-1);
    }
};
*/

/***
 * ��3��̰��
 * �������󣬼���ܷ�����0
 ***/
class Solution {
public:
    bool canJump(int A[], int n) {
        int lb = n-1;  // left bound
        for (int i = n-2; i >= 0; --i)
            if (i + A[i] >= lb)
                lb = i;
        return (lb <= 0);
    }
};