/***
 * 法1：两次遍历，第一次计数，第二次赋值
 ***/
/*
class Solution {
public:
    void sortColors(int A[], int n) {
        vector<int> vcnt(3, 0);
        for (int i = 0; i < n; ++i)
            ++vcnt[A[i]];
        int i = 0;
        for (int j = 0; j < 3; ++j)
            while (vcnt[j]--)
                A[i++] = j;
        return;
    }
};
*/

/***
 * 法2：一个遍历，用三个指针red blue i
 * red 左边0的位置，blue右边2的位置，i循环变量
 * 把0往前放，2往后放，1自然在中间
 ***/
class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0;
        int blue = n-1;
        int i = 0;
        while (i <= blue)
        {
            switch (A[i])
            {
                case 0:
                    swap(A[i++], A[red++]);
                    break;
                case 1:
                    ++i;
                    break;
                case 2:
                    swap(A[i], A[blue--]);
                    break;
            }
        }
        return;
    }
};