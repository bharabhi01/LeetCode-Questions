class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), m = cost.size();
        int sum = 0, total = 0, res = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += gas[i] - cost[i];
            if(sum < 0)
            {
                total += sum;
                sum = 0;
                res = i + 1;
            }
        }
        
        total += sum;
        
        if(total < 0)
            return -1;
        
        return res;
    }
};