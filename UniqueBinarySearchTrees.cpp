/***
 * ��1���ݹ�
 * BST�ĸ��� = �������ĸ��� * �������ĸ���
 * ö�ٸ��ڵ��λ��
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
 * ��2����̬�滮
 * dp[n] = ��{dp[i] * dp[n-i-1], 0 <= k < n}
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