/***
 * 字符串匹配
 * 法1：BF 暴力匹配，从前往后，每次haystack往后走一步
 * 时间复杂度O(m*n)
 ***/
/*
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (!needle || (*needle == '\0'))
            return haystack;
        if (!haystack)
            return NULL;
            
        while (true)
        {
            char *h = haystack;
            char *n = needle;
            while ((*n != '\0') && (*h == *n))  // strncmp(h, n, lenn)
            {
                ++h;
                ++n;
            }
            if (*n == '\0')
                return haystack;
            if (*h == '\0')
                return NULL;
            ++haystack;    // move on
        }
    }
};
*/

// 法1的另一种实现 O(n^2)
/*
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        const int lenh = strlen(haystack);
        const int lenn = strlen(needle);
        
        int i = 0;
        int j = 0;
        while ((i < lenh) && (j < lenn))
        {
            if (haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                i = i - j + 1;
                j = 0;
            }
        }
        if (j == lenn)
            return haystack + (i - j);
        else
            return NULL;
    }
};
*/

/***
 * 法2: KMP  http://www.matrix67.com/blog/archives/115/
 *      BF 时间复杂度m*n，空间复杂度O(1)
 *      KMP 时间复杂度m+n，空间复杂度O(m)
 *      适配时i不用回溯，j 应该往前跳的值就是j的next值，它是由T串本身固有决定的，与S串(主串)无关。
 *      next数组
 *      当发生失配的情况下，j的新值next[j]取决于模式串中T[0 ~ j-1]中前缀和后缀相等部分的长度，
 *      并且next[j]恰好等于这个最大长度。
 ***/
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (!needle || (*needle == '\0'))
            return haystack;
        if (!haystack)
            return NULL;
            
        int pos = kmp(haystack, needle);
        if (-1 == pos)
            return NULL;
        else
            return haystack + pos;
    }
private:
    // 由模式串T求出next[]，模式串自我匹配
    // 模式串T[0, k] 和 T[j-k-1, j]
    //           / max{k | 0<k<j, T[0, k-1] = T[j-k, j-1]}  构造最大后缀长度数组
    // next[j] = - -1, when j = 0 （此时需要主串移动i++）
    //           \ 0, others
    void get_next(const char *T, vector<int> &next)
    {
        const int len = strlen(T);
        next[0] = -1;       // init!!!
        int j = 0;
        int k = -1;
        while (j < len-1)   // not lent here, maybe ++j later!!!
        {
            if ((-1 == k) || (T[j] == T[k]))  // start || match
            {
                ++k;
                ++j;
                next[j] = k;
            }
            else
                k = next[k];  // back tracking
        }
    }
    void get_nextval(const char *T, vector<int> &next)
    {
        const int len = strlen(T);
        next[0] = -1;       // init!!!
        int j = 0;
        int k = -1;
        while (j < len-1)   // not lent here, maybe ++j later!!!
        {
            if ((-1 == k) || (T[j] == T[k]))  // start || match
            {
                ++k;
                ++j;
                if (T[j] != T[k])
                    next[j] = k;
                else
                    next[j] = next[k];
            }
            else
                k = next[k];  // back tracking
        }
    }    
    int kmp(const char *S, const char *T)
    {
        const int n = strlen(S);
        const int m = strlen(T);
        
        vector<int> next(m);
        //get_next(T, next);
        get_nextval(T, next);
        
        int i = 0;
        int j = 0;
        while ((i < n) && (j < m))
        {
            if ((-1 == j) || (S[i] == T[j]))
            {
                i++;
                j++;
            }
            else
                j = next[j];     // 不匹配时, i不变，j回溯到next[j]
        }
        
        if (j >= m)
            return i - j;
        else
            return -1;
    }
};