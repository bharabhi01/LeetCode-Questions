class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        
        int total = rows * cols;
        
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                int flat = i * cols + j;
                
                int newFlat = (flat + k) % total;
                
                int nr = newFlat / cols;
                int nc = newFlat % cols;
                ans[nr][nc] = grid[i][j];
            }
        }
        
        return ans;
    }
};