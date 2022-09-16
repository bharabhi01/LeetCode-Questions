class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) { 
        int n = nums.size();
        int m = multipliers.size();
        
        int dp[m + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = i; j >= 0; j--)
            {
                int mult = multipliers[i];
                int right = n - 1 - (i - j);
                
                int op1 = mult * nums[right] + dp[i + 1][j];
                int op2 = mult * nums[j] + dp[i + 1][j + 1];
                
                dp[i][j] = max(op1, op2);
            }
        }
        
        return dp[0][0];
    }
};