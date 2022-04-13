class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int row1 = 0, row2 = n - 1;
        int col1 = 0, col2 = n - 1;
        
        int value = 0;
        
        vector<vector<int>>ans(n, vector<int>(n));
        
        while(row1 <= row2 && col1 <= col2)
        {
            for(int i = col1; i <= col2; i++)
                ans[row1][i] = ++value;
            
            for(int i = row1 + 1; i <= row2; i++)
                ans[i][col2] = ++value;
            
            for(int i = col2 - 1; i >= col1; i--)
                ans[row2][i] = ++value;
            
            for(int i = row2 - 1; i > row1; i--)
                ans[i][col1] = ++value;
            
            row1++;
            col1++;
            row2--;
            col2--;
        }
        
        return ans;
    }
};