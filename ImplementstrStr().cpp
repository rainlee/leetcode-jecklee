/***
 * �ַ���ƥ��
 * ��1��BF ����ƥ�䣬��ǰ����ÿ��haystack������һ��
 * ʱ�临�Ӷ�O(m*n)
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

// ��1����һ��ʵ�� O(n^2)
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
 * ��2: KMP  http://www.matrix67.com/blog/archives/115/
 *      BF ʱ�临�Ӷ�m*n���ռ临�Ӷ�O(1)
 *      KMP ʱ�临�Ӷ�m+n���ռ临�Ӷ�O(m)
 *      ����ʱi���û��ݣ�j Ӧ����ǰ����ֵ����j��nextֵ��������T��������о����ģ���S��(����)�޹ء�
 *      next����
 *      ������ʧ�������£�j����ֵnext[j]ȡ����ģʽ����T[0 ~ j-1]��ǰ׺�ͺ�׺��Ȳ��ֵĳ��ȣ�
 *      ����next[j]ǡ�õ��������󳤶ȡ�
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
    // ��ģʽ��T���next[]��ģʽ������ƥ��
    // ģʽ��T[0, k] �� T[j-k-1, j]
    //           / max{k | 0<k<j, T[0, k-1] = T[j-k, j-1]}  ��������׺��������
    // next[j] = - -1, when j = 0 ����ʱ��Ҫ�����ƶ�i++��
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
                j = next[j];     // ��ƥ��ʱ, i���䣬j���ݵ�next[j]
        }
        
        if (j >= m)
            return i - j;
        else
            return -1;
    }
};