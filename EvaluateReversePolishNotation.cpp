/***
 * ջ
 * �沨��ʽ�Ǻ�׺���ʽ
 * ������ѹջ����������ջ�����Ƕ�Ԫ����������������������
 * ��������󣬽����ѹջ
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
 * ��2���ݹ�
 * �Ӻ���ǰ�������ǲ�������ݹ鴦�������������������ؽ��
 * ���ǲ���������ֱ�ӷ���
 * ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(logn)
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