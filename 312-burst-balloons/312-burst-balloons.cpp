class Solution {
public:
    int func(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i >= j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int maxi = INT_MIN;
        
        for(int k = i; k < j; k++)
        {
            int steps = (nums[i - 1] * nums[k] * nums[j]) + func(i, k, nums, dp) + func(k + 1, j, nums, dp);
            
            maxi = max(maxi, steps);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        
        return func(1, n - 1, nums, dp);
    }
};