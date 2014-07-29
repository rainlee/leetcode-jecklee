/***
 * ��1�������򣬺������ʱ�临�Ӷ�O(nlogn)
 * ��2���ռ任ȡʱ�䣬����hash��ֻ�豣��key������Ҫ�������ظ�Ԫ��ֻ��һ�ξͿ����ˣ�
 *      �ӵ�һ������ʼ����ǰ��ͺ�����������߼���������������õ�����󳤶ȣ����������������ֵ
 *      �Ż����ҹ���������ɾ�������������ظ����ң���Ϊ�������ε����������ʹ���
 ***/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> smap;
        for (int i = 0; i < num.size(); ++i)  // create hash map
            smap.insert(num[i]);
        
        int maxl = INT_MIN;
        for (int i = 0; (i < num.size()) && !smap.empty(); ++i)
        {
            int maxi = 1;  // max len, expend (i)
            
            int left = num[i];
            while (smap.find(--left) != smap.end())  // expend to left
            {
                smap.erase(left);  // erase visited node
                ++maxi;
            }
            int right = num[i];
            while (smap.find(++right) != smap.end())
            {
                smap.erase(right);
                ++maxi;
            }
            maxl = max(maxl, maxi);
        }
        return maxl;
    }
};