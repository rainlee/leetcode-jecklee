/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         God Bless Me     BUG Free Forever
*/

/***
 * ��1��O(n)�ռ�
 * ������ջ����ջ����Сֵջ
 * ѹջʱ������ջѹԭֵ����Сֵջѹ��ǰ��Сֵ
 * ����stl stack û���Լ�ʵ��ջ
 ***/
/*
class MinStack {
public:
    void push(int x) {
        sdata.push(x);
        smin.push(((smin.empty() || (x < smin.top()))) ? x : smin.top());
    }

    void pop() {
        if (!sdata.empty())
        {
            sdata.pop();
            smin.pop();
        }
    }

    int top() {
        return sdata.top();
    }

    int getMin() {
        return smin.top();
    }
private:
    stack<int> sdata;
    stack<int> smin;
};
*/

/***
 * ��1 Memory Limit Exceeded
 * ��2���Ż���Сջ
 * ����Сֵ�������仯ʱ�������ظ�ѹ��Сջ������һ����������¼��Сֵ�Ĵ��������㵯ջ��
 * ���û�м�����-2 -2�����ڶ���-2 popʱ����СջҲ��pop -2������
 ***/
/*
class MinStack {
public:
    void push(int x) {
        sdata.push(x);
        if (smin.empty() || (x < smin.top().first))
            smin.push(make_pair(x, 1));
        else
            smin.top().second++;
    }
    void pop() {
        if (!sdata.empty())
        {
            sdata.pop();
            if (--smin.top().second == 0)
                smin.pop();
        }
    }
    int top() {
        return sdata.top();
    }
    int getMin() {
        return smin.top().first;
    }
private:
    stack<int> sdata;
    stack<pair<int, int> > smin;  // (value, count)
};
*/

/***
 * ��3: O(n)ʱ�� O(1)�ռ�
 * ���ö������Сջ��ֻ��һ��ȫ�ֵ�minv��¼��Сֵ
 * pushʱ
 * �� x >= minvʱ��ѹ��ԭֵ��minv����
 * �� x < minv, ѹ��x - 2*minv(��ֵ < x)������ minv = x
 * popʱ
 * �� s.top() >= minv��ֱ�ӵ���
 * �� s.top() < minv����ԭ��һ����Сֵ minv = (minv - s.top()) / 2, ����minv
 * topʱ
 * ����max(s.top(), minv)
 * ע�����ܻ��������
 ***/
class MinStack {
public:
    MinStack(): minv(0) {}
    void push(int x) {
        if (sdata.empty() || (x < minv))
        {
            sdata.push(x - 2*minv);
            minv = x;
        }
        else
            sdata.push(x);
    }
    void pop() {
        if (!sdata.empty())
        {
            if (sdata.top() < minv)
                minv = (minv - sdata.top()) / 2;
            sdata.pop();
        }
    }
    int top() {
        return max(sdata.top(), minv);
    }
    int getMin() {
        return minv;
    }
private:
    stack<int> sdata;
    int minv;
};