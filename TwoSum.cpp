/***
 * ��1�������򣨱���ԭ������λ�ã�
 * Ȼ��������ָ����������м����
 * ������֮�� sum > target����--high
 * ��sum < target, ++low
 * ʱ�临�Ӷ�O(nlogn)
 ***/
/*
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> vret(2, 0);
        const int n = numbers.size();
        if (0 == n)
            return vret;
        
        vector<pair<int, int> > vnums(n);  // (num, index)
        for (int i = 0; i < n; ++i)
            vnums[i] = make_pair(numbers[i], i+1);
        
        sort(vnums.begin(), vnums.end(), pcmp);   // sort
        
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            int sum = vnums[low].first + vnums[high].first;
            if (sum == target)
                break;
            else if (sum > target)
                --high;
            else
                ++low;
        }
        vret[0] = std::min(vnums[low].second, vnums[high].second);
        vret[1] = std::max(vnums[low].second, vnums[high].second);
        
        return vret;
    }
private:
    static bool pcmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return (a.first < b.first);
    }
};
*/

/***
 * ��ϣ
 * �洢ÿ����Ӧ���±꣨����ͬ��ʱ����bug��8 = 4+4��
 * ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(n)
 * map���ܴ���ͬ������ÿ�ζ������ͬ�������һ��
 * �����8=4+4���ҵ����ǵڶ��������������
 ***/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> vret(2, 0);
        const int n = numbers.size();
        if (0 == n)
            return vret;
            
        unordered_map<int, int> mnums;
        for (int i = 0; i < n; ++i)
            mnums[numbers[i]] = i + 1;
        
        for (int i = 0; i < n; ++i)
        {
            int dif = target - numbers[i];
            if ((mnums.find(dif) != mnums.end()) && (mnums[dif] != i+1)) // found
            {
                vret[0] = i + 1;
                vret[1] = mnums[dif];
                break;
            }
        }
        return vret;
    }
};