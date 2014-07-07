/***
 * ̰�ķ�
 * ˮ��ȡ�������߽ϵ͵�ľ��
 * ����ָ�룬���Ҽбƣ�����󳤶ȿ�ʼ
 * ÿ��������С��һ��
 * ��չ��������������б�������ˮ����
 * ��ʱ��ˮ����һ�����Σ��ϵ�height[low]���µ�height[high]����high-low
 ***/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxA = 0;
        int low = 0;
        int high = height.size() - 1;
        while (low < high)
        {
            int area = min(height[low], height[high]) * (high - low);
            maxA = max(maxA, area);
            
            if (height[low] < height[high])
                ++low;
            else
                --high;
        }
        return maxA;
    }
};