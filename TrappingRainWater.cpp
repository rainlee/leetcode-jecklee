/***
 * 同Best Time to Buy and Sell Stock III
 * i位置的水位取决于左右最大的水深中的较小值
 * 用maxhl[i]保存左边的最小水深，maxhr[i]保存右边的最小水深
 * 同样的，可以优化空间，只用一个数组保存maxhr[]，maxhl用一个变量动态更新
 * 时间复杂度O(n) 空间复杂度O(n)
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
 * 找到最高的柱子maxh，以maxh为分界点
 * maxhl - maxh - maxhr 左边只用考虑左边界，右边只用考虑右边界
 * 时间复杂度O(n)，空间复杂度O(1)
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
 * 类似Largest Rectangle in Histogram
 * 用一个辅助栈，记录下左边柱子的索引，是一个单调递减序列
 * 当栈为空 || 当前元素小于栈顶元素时入栈
 * 反之，出栈，并计算水深和容量；知道满足以上入栈条件
 * 之前计算容量的方法是纵向的，一次计算一列的容积
 * 本方法是横向的，出栈时A[s.top()] A[i]构成左右两边界，h是右边一个柱子的高度（计算高度差）
 * 算出高min(A[s.top()], A[i]) - h，宽i - s.top() - 1的水带
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
