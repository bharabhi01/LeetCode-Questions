class Solution {
public:
    int helper(int ind, vector<int>& nums, int target, int n, vector<int>& dp) {
        if(target == 0) 
            return 1;
        
        int ans = 0;
        
        if(dp[target] != -1) 
            return dp[target];
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= target)
                ans += helper(i, nums, target - nums[i], n, dp);
        }
        
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target + 1, -1);
        
        return helper(0, nums, target, n, dp);
    }
};