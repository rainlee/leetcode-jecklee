/***
 * DFS
 * ÿ��ȡһ�����֣�ö�ٸ����ֿ��ܵ���ĸ
 * Ϊ���㴦����һ��ȫ�ֵ�����-��ĸӳ���
 ***/
const string num2let[] = {"", "", "abc", "edf", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string path;
        dfs(digits, path);
        
        return vcoms;
    }
private:
    vector<string> vcoms;
    
    void dfs(string &digits, string &path) // deep = path.size()
    {
        if (path.size() == digits.size())
        {
            vcoms.push_back(path);
            return;
        }
        string lets = num2let[digits[path.size()] - '0'];  // get table
        for (int i = 0; i < lets.size(); ++i)
        {
            path.push_back(lets[i]);
            dfs(digits, path);
            path.pop_back();
        }
        return;
    }
};