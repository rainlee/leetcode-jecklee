/***
 * �ֿ����
 * ÿ���ҵ�����i
 * ����i֮ǰ�ľ������
 * ʱ�临�Ӷ�O(n^2)
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
 * ��2���ø���ջ��ͬ�����Ҳ���
 * ջ��ά�����ǵ�����height��Ӧ������
 * ��ǰԪ��С��ջ��Ԫ��ʱ����ջ
 * ���򣬺ϲ�����ջ��ֱ��ջ��Ԫ��С�ڵ�ǰԪ��
 * Ϊ�������һ�εĴ�����height��ĩβѹ��0
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