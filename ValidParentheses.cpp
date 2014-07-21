/***
 * Õ»
 * ×óÀ¨ºÅ{[( ÈëÕ»£¬ÓÒÀ¨ºÅ )]}³öÕ»
 ***/
class Solution {
public:
    bool isValid(string s) {
        
        stack<char> spare;
        for (int i = 0; i < s.size(); ++i)
        {
            if ((s[i] == '{') || (s[i] == '[') || (s[i] == '('))
                spare.push(s[i]);
            else
            {
                if (spare.empty())
                    return false;
                char cpre = spare.top();
                if ( ((cpre == '{') && (s[i] != '}')) || 
                     ((cpre == '[') && (s[i] != ']')) ||
                     ((cpre == '(') && (s[i] != ')')) )
                    return false;
                else
                    spare.pop();
            }
        }
        return spare.empty();
    }
};