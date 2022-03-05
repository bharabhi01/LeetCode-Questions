class Solution {
public:
    int func(vector<int> &nums, int i, vector<int> &dp)
    {
        if(i >= nums.size())
            return 0;

        int currValue = nums[i];  
        int currSum = nums[i]; 
        int index = i + 1; 
        
        if(dp[i] != -1)
            return dp[i];

        while(index < nums.size() && nums[index] == currValue)
        {
            currSum += nums[i];
            index++;
        }

        while(index < nums.size() && nums[index] == currValue + 1)
            index++;

        return dp[i] = max(currSum + func(nums, index, dp), func(nums, i + 1, dp));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);

        sort(nums.begin(), nums.end());
        
        return func(nums, 0, dp);
    }
};