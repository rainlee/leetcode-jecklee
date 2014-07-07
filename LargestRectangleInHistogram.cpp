/***
 * 分块计算
 * 每次找到波峰i
 * 遍历i之前的矩形面积
 * 时间复杂度O(n^2)
 ***/
/***
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int maxRA = 0;
        const int n = height.size();
        
        for (int i = 0; i < n; ++i)
        {
            if ((i < n-1) && (height[i] <= height[i+1]))  // not last || not local highest
                continue;
            
            int minh = height[i];
            for (int j = i; j >= 0; --j)  // foreach the start of rectangle
            {
                minh = std::min(minh, height[j]);
                maxRA = std::max(maxRA, (i-j+1) * minh);
            }
        }
        return maxRA;
    }
};
***/

/***
 * 法2：用辅助栈，同样是找波峰
 * 栈中维护的是递增的height对应的索引
 * 当前元素小于栈顶元素时，入栈
 * 否则，合并现有栈，直到栈顶元素小于当前元素
 * 为方便最后一段的处理，在height的末尾压入0
 ***/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int maxRA = 0;
        height.push_back(0);     // ensure every segment will be processed
        const int n = height.size();
        stack<int> shi;          // height index
        
        for (int i = 0; i < n; )
        {
            if (shi.empty() || (height[i] >= height[shi.top()]))
                shi.push(i++);
            else
            {
                int minhi = shi.top();
                shi.pop();
                int width = shi.empty() ? i : (i - shi.top() - 1);   // if stack is empty, width is equal to i
                maxRA = std::max(maxRA, height[minhi] * width);
            }
        }
        return maxRA;
    }
};