/***
 * �����Word Ladder��������Ҫ��¼���е���̱任·��
 * ��ÿ��·����Ȼʹ��BFS��ö��26����ĸ�滻�ַ����е�һ���ַ� ���ת������
 * ����õ��ʴ���dict����δ��ʹ�ã���ʹ���� ��������һ��
 * ���һ�㣬�滻�ַ���Ϊend
 * ����ͬһ���п����ж����ѡ���浥�ʣ�����Ҫ������
 * ʹ��һ��ǰ�����ʱ���¼ÿһ�����ʵ�ǰ����������Щ��
 * �ڱ�����Ϻ󣬴�end�����ݹ���������·����
 * ʹ������set��ģ����еĲ�������set 1�б������ʽ���ת�����ԣ�������ת���ĵ��ʺ������set 2�С�
 * ��set 1�еĵ��ʴ�����Ϻ�Ϊһ�㴦����ϣ�������ĵ��ʾͿ��Դ��ֵ���ɾȥ�ˡ�
 * ��set 2����ͬ��������˷���ֱ����ǰ�����set�в����е��ʡ�
 * set 1��set 2�ڲ��ϵؽ��������������ʹ�������������ݣ�����ͨ���������һ�������У�ÿ��ѭ���������±�ֵȡ��ʵ����ݵĽ���.
 * ע�⣺ÿ��һ�㴦�����ˣ����ܰѸò����д�����ĵ��ʴ�dictɾ��
 ***/
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<unordered_set<string> > vlevel(2);         // mark cur pre level
        int cur = 0;  // mark cur level
        int pre = 1;
        vlevel[cur].insert(start);  // 1st level
        dict.insert(end);           // last level
        
        while (true)
        {
            cur = !cur;  // swap cur pre
            pre = !pre;
            vlevel[cur].clear();  // caution!!!
            
            // erase visited words!!!
            for (unordered_set<string>::iterator it = vlevel[pre].begin(); it != vlevel[pre].end(); ++it)
                dict.erase(*it);
                
            // process the words in pre level
            for (unordered_set<string>::iterator it = vlevel[pre].begin(); it != vlevel[pre].end(); ++it)
            {
                string word = *it;
                for (int i = 0; i < word.size(); ++i)  // BFS
                {
                    char cpre = word[i];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (c == cpre)
                            continue;
                        word[i] = c;    // change
                        if (dict.find(word) != dict.end())  // in dict
                        {
                            vlevel[cur].insert(word);
                            mpremap[word].push_back(*it);   // *it, orignal word
                        }
                    }
                    word[i] = cpre; // restore
                }
            }
            if (vlevel[cur].empty())  // not found
                return vvladders;
            if (vlevel[cur].find(end) != vlevel[cur].end())  // found "end"
                break;
        } // end of while
        
        if (!mpremap.empty())
        {
            vector<string> vpath;
            genPaths(vpath, end);  // bottom to top
        }
        
        return vvladders;
    }
private:
    unordered_map<string, vector<string> > mpremap;     // previous map
    //vector<unordered_set<string> > vlevel(2);         // mark cur pre level
    vector<vector<string> > vvladders;                  // result
    
    // gen the all paths recursively form bottom to top
    void genPaths(vector<string> &vpath, string word)
    {
        if (0 == mpremap.count(word))  // no former - find 'start'
        {
            vector<string> vrepath(vpath);
            vrepath.push_back(word);      // "start"
            reverse(vrepath.begin(), vrepath.end());
            
            vvladders.push_back(vrepath);
            
            return;
        }
        
        vpath.push_back(word);    // put cur word in vpath
        vector<string> &vpres = mpremap[word];  // foreach the pres
        for (vector<string>::iterator it = vpres.begin(); it != vpres.end(); ++it)
            genPaths(vpath, *it);
        vpath.pop_back();     // restore
        return;
    }
};