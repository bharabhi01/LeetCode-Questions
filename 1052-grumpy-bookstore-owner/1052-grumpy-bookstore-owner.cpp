class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), sum = 0, start = 0;
        int end = start + minutes - 1;
        
        for(int i = 0; i < n; i++)
            if(grumpy[i] == 0)
                sum += customers[i];
        
        int satisfaction = sum;
        int tempSum = 0;

        for(int i = start; i <= end; i++)
            if(grumpy[i] == 1)
                tempSum += customers[i];
        
        int maxWindowSum = tempSum;
        start++;
        end++;
        
        while(end < n)
        {
            if(grumpy[start - 1] == 1)
                tempSum -= customers[start - 1];
            
            if(grumpy[end] == 1)
                tempSum += customers[end];
            
            maxWindowSum = max(tempSum, maxWindowSum);
            
            start++;
            end++;
        }
        
        return (satisfaction + maxWindowSum);
    }
};