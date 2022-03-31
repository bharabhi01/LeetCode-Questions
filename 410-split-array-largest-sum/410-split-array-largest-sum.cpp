class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        vector<int>prev(n, 0);
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, INT_MAX));
        
        prev[0] = nums[0];
        
        for(int i = 1; i < n; i++)
            prev[i] = prev[i - 1] + nums[i];
        
        for(int i = 0; i < n; i++)
            dp[i][1] = prev[i];
        
        dp[0][0] = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 2; j <= m; j++)
            {
                for(int k = 0; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], prev[i] - prev[k]));
                }
            }
        }
        
        return dp[n - 1][m];
    }   
};