/***
 * 深搜
 * 深度为4，且必须走到底
 ***/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string ip;
        dfs(s, 0, 0, ip);
        return vips;
    }
private:
    vector<string> vips;
    
    void dfs(string &s, int deep, int start, string ip)
    {
        if (4 == deep)
        {
            if (start == s.size())
                vips.push_back(ip);
            return;
        }
        if (deep > 0)
            ip += '.';
            
        int num = 0;
        for (int i = start; i < s.size(); ++i)
        {
            num = num*10 + (s[i] - '0');
            if (num > 255)
                break;
            ip += s[i];
            dfs(s, deep+1, i+1, ip);
            if (0 == num)   // 0 is legal, but cant be prefix, like 01.
                break;
        }
        return;
    }
};