/***
 * 两个库函数pre_permutation next_permutation, 返回值bool
 * 以上库函数原理
 * next_permutation 前面小的和后面大的置换
 * 范围由[first,last)标记，根据标记从后往前比较相邻两数据，
 * 若前者小于（默认为小于）后者，标志前者为X1（位置PX）表示将被替换，
 * 再次从后往前搜索第一个大于X1的数据，标记为X2。交换X1，X2，（可以在第一次遍历时记录）
 * 然后把[PX+1，last)标记范围置逆。
 * 要点：为什么这样就可以保证得到的为最小递增。
 * 从位置first开始原数列与新数列不同的数据位置是PX，并且新数据为X2。[PX+1，last)总是递减的，[first,PX)没有改变，
 * 因为X2>X1,所以不管X2后面怎样排列都比原数列大，反转[PX+1，last)使此子数列(递增)为最小。
 * 从而保证的新数列为原数列的字典序排列next。
 * 
 * 类似的思想可以求pre_permutation 前面大的和后面小的置换
 * 从后往前遍历，找到第一个相邻的X1>X2，X1将被替换（把大的往后移）
 * 再次从后往前遍历，找到第一个小于X1的数据X3，交换X1 X3
 * 然后把[X2 last) 逆置（使此子数列递减）
 ***/
/*
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int x1 = -1;
        int x2 = -1;
        
        for (int i = num.size()-2; i >= 0; --i)
        {
            if (num[i] < num[i+1])
            {
                x1 = i;
                break;
            }
        }
        
        if (x1 >= 0)
        {
            for (int i = num.size()-1; i > x1; --i)
            {
                if (num[i] > num[x1])
                {
                    x2 = i;
                    break;
                }
            }
            swap(num[x1], num[x2]);
        }
        sort(num.begin() + x1 + 1, num.end());  // including x1 = 0, reverse the reset array
        return;
    }
};
*/

/***
 * 法2：一种更简洁的代码
 ***/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size() - 1;
        while ((i > 0) && (num[i] <= num[i-1]))
            --i;
        reverse(num.begin() + i, num.end());  // reverse [i, n-1]
        if (0 == i)
            return;
        
        int j = i;
        while ((j < num.size()) && (num[j] <= num[i-1]))
            ++j;
        swap(num[i-1], num[j]);
        return;
    }
};