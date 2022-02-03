class Solution {
public:
    int fiba(int n, vector<int>&dp)
    {
        if(n <= 1)
            return n;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = fiba(n-1, dp) + fiba(n-2, dp);
    }
    
    int fib(int n) {
        vector<int>dp(n + 1, -1);
        
        return fiba(n, dp);
    }
};