/***
 * 栈
 * 逆波兰式是后缀表达式
 * 操作数压栈，操作符弹栈（都是二元操作符，弹两个操作数）
 * 进行运算后，结果再压栈
 ***/
/*
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if ((isdigit(tokens[i][0])) || (tokens[i].size() > 1))  // isdigit, maybe negative + -
                s.push(atoi(tokens[i].c_str()));
            else
            {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                
                switch (tokens[i][0])
                {
                    case '+':
                        s.push(num1 + num2);
                        break;
                    case '-':
                        s.push(num1 - num2);
                        break;
                    case '*':
                        s.push(num1 * num2);
                        break;
                    case '/':
                        s.push(num1 / num2);
                    default:
                        break;
                }
            }
        }
        return s.top();
    }
};
*/

/***
 * 法2：递归
 * 从后往前处理，若是操作符则递归处理两个操作数，并返回结果
 * 若是操作数，则直接返回
 * 时间复杂度O(n) 空间复杂度O(logn)
 ***/
class Solution {
public:
    int evalRPN(vector<string> &tokens)
    {
        string token = tokens.back();  // get last string, suffix
        tokens.pop_back();
        
        int op = 0;
        if ((isdigit(token[0])) || (token.size() > 1))
            op = stoi(token);
        else
        {
            int num2 = evalRPN(tokens);   // num2 first
            int num1 = evalRPN(tokens);
            
            switch (token[0])
            {
                case '+':
                    op = num1 + num2;
                    break;
                case '-':
                    op = num1 - num2;
                    break;
                case '*':
                    op = num1 * num2;
                    break;
                case '/':
                    op = num1 / num2;
                    break;
                default:
                    break;
            }
        }
        return op;
    }
};