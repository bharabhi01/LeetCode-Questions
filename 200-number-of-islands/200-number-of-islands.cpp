class Solution {
public:
    void eraseIsland(int i, int j, vector<vector<char>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        
        if(i < 0 || i == n || j < 0 || j == m || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        eraseIsland(i-1, j, grid);
        eraseIsland(i+1, j, grid);
        eraseIsland(i, j+1, grid);
        eraseIsland(i, j-1, grid);  
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {   
                    count++;
                    eraseIsland(i, j, grid);
                }
            }
        }
        
        return count;
    }
};