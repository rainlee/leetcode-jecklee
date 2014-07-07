/***
 * ������Ȼ��ȡһ��������ʣ�µ���ʹ��TwoSum
 * �����ƹ㵽k-sum��������Ȼ����k-2��ѭ���������ڲ�ʹ��2Sum
 * O(nlogn + n^2) = O(n^2)
 * ע��ȥ�أ�
 * ���ѭ�����Ѿ����������ͬ���ֲ��ٴ���
 * �ڴ�ѭ�����ҵ�һ���������ظ��Ĳ��ٴ���
 * ����һ���Ǵ�����֮����ȥ�أ�ʹ��unique�⺯��
 ***/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        const int n = num.size();
        if (0 == n)
            return vvsums;
        
        sort(num.begin(), num.end());   // sort first!
        
        for (int i = 0; i < n; ++i)
        {
            if ((i > 0) && (num[i] == num[i-1]))
                continue;
            twoSum(num, i+1, -num[i]);   
        }
        
        //sort(vvsums.begin(), vvsums.end());
        //vvsums.erase(unique(vvsums.begin(), vvsums.end()), vvsums.end());  // erase the dups
        
        return vvsums;
    }
private:
    vector<vector<int> > vvsums;
    
    void twoSum(vector<int> &num, int start, int target)
    {
        vector<int> vret(3);
        vret[0] = -target;
        
        int low = start;
        int high = num.size() - 1;
        
        while (low < high)
        {
            int sum = num[low] + num[high];
            if (sum == target)
            {
                vret[1] = num[low];
                vret[2] = num[high];
                vvsums.push_back(vret);
                
                //++low;
                //--high;
                
                while ((num[++low] == num[low-1]) && (low < high)) ;   // remove dups
                while ((num[--high] == num[high+1]) && (low < high));
            }
            else if (sum > target)
                --high;
            else
                ++low;
        }
        return;
    }
};