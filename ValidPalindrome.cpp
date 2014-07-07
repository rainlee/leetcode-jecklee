/***
 * 高低指针，左右夹逼
 * 跳过标点符号和空格
 ***/
class Solution {
public:
    bool isPalindrome(string s) {
        const int n = s.size();
        if (n < 2)
            return true;
        
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            while (!isalnum(s[low]) && (low < high)) ++low;
            while (!isalnum(s[high]) && (low < high)) --high;
            
            if ((low < high) && (tolower(s[low++]) != tolower(s[high--])))
                return false;
        }
        return true;
    }
};