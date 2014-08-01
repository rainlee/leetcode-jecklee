/***
 * ͬBest Time to Buy and Sell Stock III
 * iλ�õ�ˮλȡ������������ˮ���еĽ�Сֵ
 * ��maxhl[i]������ߵ���Сˮ�maxhr[i]�����ұߵ���Сˮ��
 * ͬ���ģ������Ż��ռ䣬ֻ��һ�����鱣��maxhr[]��maxhl��һ��������̬����
 * ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(n)
 ***/
/*
class Solution {
public:
    int trap(int A[], int n) {
        if (n < 3)
            return 0;
        
        vector<int> maxhr(n);   // max height in right
        maxhr[n-1] = A[n-1];
        for (int i = n-2; i >= 0; --i)
            maxhr[i] = max(A[i], maxhr[i+1]);
        
        int maxhl = A[0];       // max height in left
        int sum = 0;
        for (int i = 1; i < n; ++i)
        {
            maxhl = max(maxhl, A[i]);
            int dep = min(maxhl, maxhr[i]) - A[i];   // max deep in ith
            sum += (dep > 0) ? dep : 0;
        }
        return sum;
    }
};
*/

/***
 * �ҵ���ߵ�����maxh����maxhΪ�ֽ��
 * maxhl - maxh - maxhr ���ֻ�ÿ�����߽磬�ұ�ֻ�ÿ����ұ߽�
 * ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
 ***/
/*
class Solution {
public:
    int trap(int A[], int n) {
        if (n < 3)
            return 0;
        
        int maxhi = 0;   // index
        for (int i = 0; i < n; ++i)
            if (A[i] > A[maxhi])
                maxhi = i;
                
        int sum = 0;        // water
        int maxhl = A[0];   // max left hieight
        for (int i = 1; i < maxhi; ++i)
        {
            maxhl = max(maxhl, A[i]);
            sum += maxhl - A[i];
        }
        
        int maxhr = A[n-1];
        for (int i = n-2; i > maxhi; --i)
        {
            maxhr = max(maxhr, A[i]);
            sum += maxhr - A[i];
        }
        return sum;
    }
};
*/

/***
 * ����Largest Rectangle in Histogram
 * ��һ������ջ����¼��������ӵ���������һ�������ݼ�����
 * ��ջΪ�� || ��ǰԪ��С��ջ��Ԫ��ʱ��ջ
 * ��֮����ջ��������ˮ���������֪������������ջ����
 * ֮ǰ���������ķ���������ģ�һ�μ���һ�е��ݻ�
 * �������Ǻ���ģ���ջʱA[s.top()] A[i]�����������߽磬h���ұ�һ�����ӵĸ߶ȣ�����߶Ȳ
 * �����min(A[s.top()], A[i]) - h����i - s.top() - 1��ˮ��
 ***/
class Solution {
public:
    int trap(int A[], int n) {
        if (n < 3)
            return 0;
        
        int sum = 0;
        stack<int> s;
        int i = 0;
        while (i < n)
        {
            if (s.empty() || (A[i] < A[s.top()]))
                s.push(i++);
            else
            {
                int h = 0;
                while (!s.empty())
                {
                    int depth = min(A[i], A[s.top()]) - h;   // h is in right of s.top()
                    int width = i - s.top() - 1;
                    sum += depth * width;
                    h = A[s.top()];        // update h
                    
                    if (A[s.top()] > A[i]) // process all bars in right of this A[s.top()]
                        break;
                    else
                        s.pop();
                }
            }
        }
        return sum;
    }
};
