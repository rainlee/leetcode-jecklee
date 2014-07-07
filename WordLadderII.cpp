/***
 * 类比于Word Ladder，本题需要记录所有的最短变换路径
 * 求每条路径仍然使用BFS，枚举26个字母替换字符串中的一个字符 组成转换单词
 * 如果该单词存在dict中且未被使用，则使用它 并进入下一层
 * 最后一层，替换字符串为end
 * 由于同一层中可能有多个待选的替单词，都需要记下来
 * 使用一个前驱单词表，记录每一个单词的前驱单词是哪些。
 * 在遍历完毕后，从end出发递归生成所有路径。
 * 使用两个set来模拟队列的操作。从set 1中遍历单词进行转换尝试，发现能转换的单词后将其放入set 2中。
 * 当set 1中的单词处理完毕后即为一层处理完毕，它里面的单词就可以从字典里删去了。
 * 对set 2进行同样处理，如此反复直到当前处理的set中不再有单词。
 * set 1和set 2在不断地交换正处理容器和待处理容器的身份，可以通过将其放入一个数组中，每次循环对数组下标值取反实现身份的交替.
 * 注意：每次一层处理完了，才能把该层所有处理过的单词从dict删除
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