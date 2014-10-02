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
 * ��1��ģ��
 *      ö����㣬ʱ�临�Ӷ�O(n^2)
 * ��2��̰��
 * ��0�����������������������left��ʾ��istart��ʼʣ�������
 * ��left < 0��˵������ͨ��i����i+1������i֮ǰ�����е㶼������Ϊ���
 * ��Ϊ����ѡ��j(j < i) Ϊ��㣬��j��ʣ����Ϊ0����һ�α�����j����ʣ����>0�����ܵ���i+1��
 * ���ڸ��Ӳ��ܴﵽ�ˣ����Բ���ѡ��j��Ϊ���
 * ����ѡ��i+1��Ϊ�µ���㣬���ֱ��n-1
 * ���⣬sum��ʾ��0��ʼʣ�������
 * �����gas >= ��cost������Ա������е㣬��㼴Ϊ�����һ�μ�¼
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
 * ��2��˫ָ�룬һ��ָ����㣬һ��ָ���յ�
 * ��left>=0ʱ��˵�����Դ�start����end����end������
 * ��left< 0ʱ��˵�����ܵ����start����������
 * ���left>=0����ʾ���Ե���
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