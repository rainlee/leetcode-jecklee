/***
 * 分割字符串 分割符 '/'，模拟栈
 * 一个'.' 忽略
 * 两个'.' 回退
 * 多个'/' 只保留一个
 * "/.."
 * "/"
 * "/..." 输出 "/..."?
 * "/..hidden" 输出 "/..hidden"
 * 重新梳理一下规则：
 * 检查两个'/'中间的字符串，如果为空或者"."则忽略
 * 是".."则回退，其他的均保留（包括多个'.'）！
 * 为方便处理，在path末尾添加一个'/'
 ***/
/*
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vdir;
        path += "/";
        
        size_t pos = path.find_first_of("/");
        size_t last = 0;
        while (pos != string::npos)
        {
            string s = path.substr(last, pos - last);  // string between '/'
            if (s == "..")  // back tracking
            {
                if (!vdir.empty())
                    vdir.pop_back();
            }
            else if (!s.empty() && s != ".")  // else, do nothing
                vdir.push_back(s);
            last = pos + 1;
            pos = path.find_first_of("/", last);  // search from last
        }
        string smppath;
        for (int i = 0; i < vdir.size(); ++i)
            smppath += "/" + vdir[i];
        if (vdir.empty())
            smppath += "/";
        
        return smppath;
    }
};
*/
// 方法不变
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vs;  // stack
        path += '/';        // process the last seg
        for (int i = 1; i < path.size(); )
        {
            int j = path.find('/', i);
            string s = path.substr(i, j-i);
            if (s == "..")
            {
                if (!vs.empty())
                    vs.pop_back();
            }
            else if (!s.empty() && (s != "."))
                vs.push_back(s);
            i = j + 1;
        }
        string spaths;
        for (int i = 0; i < vs.size(); ++i)
            spaths += "/" + vs[i];
        if (vs.empty())
            spaths += "/";
        return spaths;
    }
};