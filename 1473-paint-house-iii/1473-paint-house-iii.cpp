#define ll long long
ll dp[105][25][105];

ll solve(vector<int>& houses, ll index, vector<vector<int>>& cost, ll prev, ll m, ll n, ll target)
{
    if(target < 0)              
        return INT_MAX;
    
    if(index == m)      
    {
        if(target == 0)       
            return 0;
        
        return INT_MAX;    
    }
    
    if(dp[index][prev][target] != -1)
        return dp[index][prev][target];
    
    if(houses[index] != 0)       
        return dp[index][prev][target] = solve(houses, index + 1, cost, houses[index], 
                                               m, n, target - (prev != houses[index]));
    
    ll ans = INT_MAX;         
    
    for(int i = 1; i <= n; i++)
        ans = min(ans, cost[index][i - 1] + solve(houses, index + 1, cost,
                                                  i, m, n, target - (prev != i)));
    
    return dp[index][prev][target] = ans;
}

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        ll ans = solve(houses, 0, cost, n + 1, m, n, target);
        
        if(ans == INT_MAX) 
            return -1;
        
        return ans;
    }
};