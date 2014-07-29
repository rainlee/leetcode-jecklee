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