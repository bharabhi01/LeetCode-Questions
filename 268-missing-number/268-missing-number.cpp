class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0, n = nums.size();
            
        for(int i = 1; i <= n; i++)
            total += i;
           
        int sum = 0;
        
        for(int i = 0; i < n; i++)
            sum += nums[i];
                                 
        return total - sum;
    }
};