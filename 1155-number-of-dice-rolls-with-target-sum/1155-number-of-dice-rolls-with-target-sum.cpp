class Solution {
public:
    long long dp[1001][1001];
    int MOD = 1e9 + 7;
    
    long long call(int idx, int k, int target, int& ans, int n, int val) {
        if(idx == n)
        {
            if(val == target)
                return 1;
        }
        
        if(dp[idx][val] != -1)
            return dp[idx][val];
    
        int sum = 0;
        
        for(int i = 1; i <= k; i++)
        {
            if(val + i <= target)
                sum = (sum + call(idx + 1, k, target, ans, n, val + i)) % MOD;
        }
        
        return dp[idx][val] = sum;
    }
        
    int numRollsToTarget(int n, int k, int target) {
        int ans = 0, idx = 0, val = 0;
        memset(dp, -1, sizeof(dp));
        
        int res = call(idx, k, target, ans, n, val);
        
        return res;
    }
};