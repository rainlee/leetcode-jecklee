/***
 * 法1：DFS 计数，一直到k
 * 这方法会超时
 * 法2：数学方法，分析规律 - Cantor康托编码
 * n个数字有n!个排列，即n组(n-1)!个排列（先排第一个）
 * 对第k个排列，通过对(n-1)!取余，可以知道它属于n组中的第几组
 * 商为第i组，余数为剩下n-1个数的排列
 * 先排第一个数，是i；剩下的n-1个数按从小到大排序
 * 类推，n-1个数有n-1组(n-2)!个排列
 * 因为要有序，所以交换后需要对剩余元素排序（只需要把当前要排的元素插入到前面就可以了）。
 ***/
/*
class Solution {
public:
    string getPermutation(int n, int k) {
        string sper;
        for (int i = 1; i <= n; ++i)  // init
            sper += char(i + '0');
        
        if (n <= 1)
            return sper;
        
        vector<int> fact(n);   // factorial power
        fact[0] = 1;
        for (int i = 1; i < n; ++i)
            fact[i] = fact[i-1] * i;
        
        k -= 1;   // index for 0 ~ n-1
        for (int i = 0; i < n; ++i)
        {
            int pos = k / fact[n-i-1];  // choose the item in (pos+i)
            k %= fact[n-i-1];           //  ... s[i] ... s[i+pos] ... s[n-1]
                                        //  ... s[i+pos] . s[i]. s[i+1] ... s[n-1]
            int tmp = sper[pos+i];
            for (int j = pos+i; j > i; --j)  // insert (tmp) forword in pos (i)
                sper[j] = sper[j-1];
            sper[i] = tmp;
            
            if (0 == k)  // neednt move
                break;
        }
        return sper;
    }
};
*/

/***
 * 法3：同法2，更容易理解的实现
 * 不对初始字符串sper进行前插，另外建一个结果字符串
 * 每次把当前选择的字符添加到结果字符串，并且从sper中删除
 * 另外，阶乘也不用保存0~n-1，只保存n-1，其他的可以计算得来，优化空间
 ***/
class Solution {
public:
    string getPermutation(int n, int k) {
        string sper;
        int fact = 1;
        for (int i = 1; i <= n; ++i)  // init
        {
            sper += char(i + '0');
            fact *= i;
        }
        
        if (n <= 1)
            return sper;
        
        string skper;
        --k;
        while (n)
        {
            fact /= n;   // calc factorial power
            int pos = k / fact;
            k %= fact;
            skper.push_back(sper[pos]);
            sper.erase(pos, 1);
            --n;
        }
        return skper;
    }
};