class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] != 1)
            return 0;
        
        grid[i][j] = 'v';
        
        int u = dfs(i - 1, j, grid);
        int d = dfs(i + 1, j, grid);
        int l = dfs(i, j - 1, grid);
        int r = dfs(i, j + 1, grid);
        int ans = u + d + l + r;
        
        return ans + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    area = max(area, dfs(i, j, grid));
            }
        }
        
        return area;
    }
};