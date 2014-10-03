/***
 * ̰���㷨���������� �������� ����ɨ��
 * �������ң���һ��Ϊ1����һ���ȵ�ǰ�����1������Ϊ����ֵΪ1��������֤��ÿ��ֵ����߱��ǺϷ���
 * �������󣺵�һ��Ϊԭֵ����һ���ȵ�ǰ�ߣ���ȡmax(v[i], v[i+1]+1)�����򱣳�ԭֵ��������֤��ÿ��ֵ���ұ߱��ǺϷ���
 * ע�⣺12221 ��Ӧ��ֵӦ����12121
 ***/
/*
class Solution {
public:
    int candy(vector<int> &ratings) {
        const int n = ratings.size();
        vector<int> vnum(n, 1);   // at least 1
        for (int i = 1; i < n; ++i)     // compare with the left one
            if (ratings[i] > ratings[i-1])
                vnum[i] = vnum[i-1] + 1;
        
        int sum = vnum[n-1];
        for (int i = n-2; i >= 0; --i)  // compare with the right one
        {
            if (ratings[i] > ratings[i+1])
                vnum[i] = max(vnum[i], vnum[i+1] + 1);
            sum += vnum[i];
        }
        return sum;
    }
};
*/

/***
 * ��2������һ�� ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
 * ����Ҫ��¼ÿ�����ӵõ����ǹ���Ŀ��ֻ��Ҫ��¼ǰһ�����ӵõ����ǹ���last��
 * ��ǰ����֮ǰratingȡ����ֵ�ĺ���λ��maxi���Լ���λ���Ϻ��ӵ��ǹ���maxv��
 * ͨ�����maxi��maxv���Ϳ����ж��費Ҫ���ǹ����Լ������š�
 *
 * ��¼����ֵmaxv ������maxi ��һ��Ԫ��ֵlast
 * ��ratings[i] > ratings[i-1]ʱ������maxv ����last
 *              =               , maxv = last = 1
 *              <               , ��ʱ��ǰiλ�����ٸ�1��
 * ��last > 1�����㹻������last=1��maxv���ֲ���
 *        =  , ǰ������ˣ���Ҫ����[maxi, i)
 * ��maxv�㹻�� maxv > i - maxi����ֱ�Ӳ���(maxi, i) ÿ����һ��
 *                   <=        ���򲻹�����maxv++��[maxi, i) ÿ����һ��
 ***/
class Solution {
public:
    int candy(vector<int> &ratings) {
        const int n = ratings.size();
        int last = 1;
        int sum = 1;
        int maxv = 1;   // init
        int maxi = 0;
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] >= ratings[i-1])  // increasing
            {
                last = (ratings[i] == ratings[i-1]) ? 1 : (last + 1);  // caution!!!
                maxv = last;
                maxi = i;
            }
            else     // decreasing
            {
                if (1 == last)  // last must > cur, should increase the candy [maxi, i)
                {
                    if (maxv <= i - maxi) 
                    {
                        sum += i - maxi;  // add more
                        ++maxv;
                    } 
                    else
                        sum += i - maxi - 1;
                }
                last = 1;  // update cur
            }
            sum += last;   // add cur
        }
        return sum;
    }
};