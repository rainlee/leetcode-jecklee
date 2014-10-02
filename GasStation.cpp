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
 * 法1：模拟
 *      枚举起点，时间复杂度O(n^2)
 * 法2：贪心
 * 从0往后遍历，设置两个变量，left表示从istart开始剩余的汽油
 * 若left < 0，说明不能通过i到达i+1；并且i之前的所有点都不能作为起点
 * 因为假设选择j(j < i) 为起点，在j处剩油量为0。第一次遍历到j处的剩油量>0都不能到达i+1，
 * 现在更加不能达到了，所以不能选择j作为起点
 * 所以选择i+1作为新的起点，如此直到n-1
 * 另外，sum表示从0开始剩余的汽油
 * 如果∑gas >= ∑cost，则可以遍历所有点，起点即为最近的一次记录
 * 
 ***/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() != cost.size())
            return -1;
            
        int istart = 0;    // start index
        int left = 0;      // left gas of a window
        int sum = 0;       // total left gas
        for (int i = 0; i < gas.size(); ++i)
        {
            left += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (left < 0)  // cant arrive next point (i+1)
            {
                istart = i + 1;
                left = 0;
            }
        }
        return (sum < 0) ? -1 : istart;
    }
};

/***
 * 法2：双指针，一个指向起点，一个指向终点
 * 当left>=0时，说明可以从start到达end，则end往后走
 * 当left< 0时，说明不能到达，则start往反方向走
 * 最后left>=0，表示可以到达
 ***/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.empty() || (gas.size() != cost.size()))
            return -1;
        
        const int n = gas.size();
        int start = n;
        int end = 0;
        int left = 0;
        while (start != end)
        {
            if (left >= 0)
            {
                left += gas[end] - cost[end];
                ++end;
            }
            else
            {
                --start;
                left += gas[start] - cost[start];
            }
        }
        return (left < 0) ? -1 : (start%n);
    }
};