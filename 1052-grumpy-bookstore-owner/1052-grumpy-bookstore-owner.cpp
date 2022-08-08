class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), sum = 0, start = 0;
        int end = start + minutes - 1;
        
        for(int i = 0; i < n; i++)
            if(grumpy[i] == 0)
                sum += customers[i];
        
        int satisfaction = sum;
        
        while(end < n)
        {
            int tempSum = 0;
            
            for(int i = start; i <= end; i++)
                if(grumpy[i] == 1)
                    tempSum += customers[i];
            
            satisfaction = max(satisfaction, sum + tempSum);
            
            start++;
            end++;
        }
        
        return satisfaction;
    }
};