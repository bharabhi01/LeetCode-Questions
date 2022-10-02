class Solution {
public:
    int MOD = 1e9 + 7;
    
    int numRollsToTarget(int n, int l, int target) {
        if(target < n || target > n * l) 
            return 0;
        
        vector<int>dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            int total = 0;
            
            for(int j = max(0, target - l); j <= target; j++) 
                total = (total + dp[j]) % MOD;
            
            for(int j = target; j >= 0; j--)
            {
                total = (total - dp[j] + MOD) % MOD;
                dp[j] = total;
                
                if(j - l - 1 >= 0) 
                    total = (total + dp[j - l - 1]) % MOD;
            }
        }
        
        return dp[target];
    }
};