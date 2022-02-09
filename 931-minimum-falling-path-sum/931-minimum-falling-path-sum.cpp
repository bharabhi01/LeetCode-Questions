class Solution {
public:
    int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(j<0 || j>=m)
            return 1e9;
        
        if(i==0)
            return matrix[0][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
    
        int up = matrix[i][j] + func(i - 1, j, matrix, dp);
        int leftDiag = matrix[i][j] + func(i - 1, j - 1, matrix, dp);
        int rightDiag = matrix[i][j] + func(i - 1, j + 1, matrix, dp);
    
        return dp[i][j] = min(up, min(leftDiag, rightDiag));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int mini = INT_MAX;
        
        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        for(int j = 0; j < m; j++)
        {
            int ans = func(n - 1, j, matrix, dp);
            mini = min(mini, ans);
        }
        
        return mini;
    }
};