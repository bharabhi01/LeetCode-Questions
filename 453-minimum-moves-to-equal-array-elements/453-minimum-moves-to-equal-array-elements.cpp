class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), sum = 0, mini = INT_MAX;
        
        for(int i = 0; i < n; i++)
            mini = min(mini, nums[i]);
        
        for(int i = 0; i < n; i++)
            sum += nums[i] - mini;
        
        return sum;
    }
};