/***
 * 法1：递归
 * BST的个数 = 左子树的个数 * 右子树的个数
 * 枚举根节点的位置
 ***/
/*
class Solution {
public:
    int numTrees(int n) {
        if ((0 == n) || (1 == n))
            return 1;
        
        int num = 0;
        for (int i = 0; i < n; ++i)   // enum the pos of root
            num += numTrees(i) * numTrees(n - i - 1);
        
        return num;
    }
};
*/

/***
 * 法2：动态规划
 * dp[n] = ∑{dp[i] * dp[n-i-1], 0 <= k < n}
 ***/
class Solution {
public:
    int numTrees(int n) {
        
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i)
            for (int j = 0; j < i; ++j)  // enum the pos of root
                dp[i] += dp[j] * dp[i - j - 1];
    
        return dp[n];
    }
};