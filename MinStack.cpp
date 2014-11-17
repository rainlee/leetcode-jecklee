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
 * 法1：O(n)空间
 * 用两个栈数据栈和最小值栈
 * 压栈时，数据栈压原值，最小值栈压当前最小值
 * 用了stl stack 没有自己实现栈
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
 * 法1 Memory Limit Exceeded
 * 法2：优化最小栈
 * 当最小值不发生变化时，不用重复压最小栈，增加一个计数，记录最小值的次数（方便弹栈）
 * 如果没有计数，-2 -2，当第二个-2 pop时，最小栈也会pop -2，出错
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
 * 法3: O(n)时间 O(1)空间
 * 不用额外的最小栈，只用一个全局的minv记录最小值
 * push时
 * 当 x >= minv时，压入原值，minv不变
 * 当 x < minv, 压入x - 2*minv(该值 < x)，更新 minv = x
 * pop时
 * 当 s.top() >= minv，直接弹出
 * 当 s.top() < minv，还原上一个最小值 minv = (minv - s.top()) / 2, 弹出minv
 * top时
 * 返回max(s.top(), minv)
 * 注：可能会溢出……
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