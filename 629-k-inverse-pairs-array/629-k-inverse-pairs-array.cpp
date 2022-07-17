#define N 1010
int dp[N][N];
const int MOD = 1e9+7;

class Solution {
public:
    int kInversePairs(int n, int k) {
        for(int i = 0; i <= n; i++) 
            dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            int sum = dp[i - 1][0];
            
            for(int j = 1; j <= k; j++)
            {
                if(j >= i) 
                    sum -= dp[i - 1][j - i];
                
                if(sum < 0) 
                    sum += MOD;
                
                (sum += dp[i - 1][j]) %= MOD;
                dp[i][j] = sum;
            }
        }
        
        return dp[n][k];
    }
};