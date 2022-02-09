class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>dp(n, vector<int>(m, 0));
        
        for(int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int up = matrix[i][j] + dp[i - 1][j];
                
                int leftDiag = matrix[i][j];
                if(j - 1 >= 0)
                    leftDiag += dp[i - 1][j - 1];
                else 
                    leftDiag += 1e9;
                
                int rightDiag = matrix[i][j];
                if(j + 1 < m)
                    rightDiag += dp[i - 1][j + 1];
                else 
                    rightDiag += 1e9;
                
                dp[i][j] = min(up, min(leftDiag, rightDiag));
            }
        }
        
        int mini = INT_MAX;
        
        for(int j = 0; j < m; j++)
            mini = min(mini, dp[n - 1][j]);
        
        return mini;
    }
};