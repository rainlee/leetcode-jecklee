/***
 * 广度优先遍历 BFS
 * 每次改变start的一个字符，然后step+1
 * 遍历start的每个字符
 *   遍历26个小写字母，替换start中的相应位，看dict中是否存在
 * 直到转化成end
 * 时间复杂度O(n*len*26) 
 ***/
/*
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
            return 1;
        
        queue<pair<string, int> > qpath;
        qpath.push(make_pair(start, 1));
        
        while (!qpath.empty())
        {
            pair<string, int> pfront = qpath.front();
            qpath.pop();
            
            string curword = pfront.first;
            int curstep = pfront.second;
            
            for (int i = 0; i < curword.size(); ++i)  // BFS
            {
                char cpre = curword[i];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    curword[i] = c;
                    
                    if (curword == end)     // success!
                        return curstep + 1;
                    
                    if (dict.find(curword) != dict.end())  // new word in dict
                    {
                        qpath.push(make_pair(curword, curstep + 1));
                        dict.erase(curword);            // caution: erase this word from dict, to escape duplications
                    }
                }
                curword[i] = cpre;  // restore
            }
        }
            
        return 0;  // not found
    }
};
*/

/***
 * 以上算法改变了dict
 * 如果不能改变dict，需要一个set记录已经访问的string
 ***/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
            return 1;
        
        queue<pair<string, int> > qpath;
        unordered_set<string> svisited;
        
        qpath.push(make_pair(start, 1));
        svisited.insert(start);
        
        while (!qpath.empty())
        {
            pair<string, int> pfront = qpath.front();
            qpath.pop();
            string curword = pfront.first;
            int curstep = pfront.second;
            
            for (int i = 0; i < curword.size(); ++i)
            {
                char cpre = curword[i];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    curword[i] = c;
                    if (curword == end)
                        return curstep + 1;
                    
                    // cur word not been visited && in dict
                    if ((svisited.find(curword) == svisited.end()) && (dict.find(curword) != dict.end()))
                    {
                        qpath.push(make_pair(curword, curstep + 1));
                        svisited.insert(curword);
                    }
                }
                curword[i] = cpre;
            }
        }
        return 0;
    }
};