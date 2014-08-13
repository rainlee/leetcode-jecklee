/***
 * �ָ��ַ��� �ָ�� '/'��ģ��ջ
 * һ��'.' ����
 * ����'.' ����
 * ���'/' ֻ����һ��
 * "/.."
 * "/"
 * "/..." ��� "/..."?
 * "/..hidden" ��� "/..hidden"
 * ��������һ�¹���
 * �������'/'�м���ַ��������Ϊ�ջ���"."�����
 * ��".."����ˣ������ľ��������������'.'����
 * Ϊ���㴦����pathĩβ���һ��'/'
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
// ��������
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