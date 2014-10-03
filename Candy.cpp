/***
 * 贪心算法：从左往后 从右往左 两次扫描
 * 从左往右：第一个为1，下一个比当前高则加1，否则为波谷值为1，这样保证了每个值和左边比是合法的
 * 从右往左：第一个为原值，下一个比当前高，则取max(v[i], v[i+1]+1)，否则保持原值，这样保证了每个值和右边比是合法的
 * 注意：12221 对应的值应该是12121
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
 * 法2：遍历一遍 时间复杂度O(n) 空间复杂度O(1)
 * 不需要记录每个孩子得到的糖果数目，只需要记录前一个孩子得到的糖果数last和
 * 当前孩子之前rating取极大值的孩子位置maxi，以及该位置上孩子的糖果数maxv。
 * 通过这个maxi和maxv，就可以判断需不要补糖果，以及补几颗。
 *
 * 记录极大值maxv 及索引maxi 上一个元素值last
 * 当ratings[i] > ratings[i-1]时，增加maxv 更新last
 *              =               , maxv = last = 1
 *              <               , 这时候当前i位置最少给1个
 * 若last > 1，则足够，更新last=1，maxv保持不变
 *        =  , 前面分少了，需要补齐[maxi, i)
 * 若maxv足够大 maxv > i - maxi，则直接补齐(maxi, i) 每个补一颗
 *                   <=        ，则不够补，maxv++，[maxi, i) 每个补一颗
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