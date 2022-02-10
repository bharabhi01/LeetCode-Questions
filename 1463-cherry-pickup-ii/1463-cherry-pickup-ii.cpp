class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>front(m, vector<int>(m, 0));
        vector<vector<int>>curr(m, vector<int>(m, 0));
        
        for(int j1 = 0; j1 < m; j1++)
        {
            for(int j2 = 0; j2 < m; j2++)
            {
                if(j1 == j2)
                    front[j1][j2] = grid[n - 1][j1];
                
                else
                    front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
        
        for (int i = n - 2; i >= 0; i--) 
        {
            for (int j1 = 0; j1 < m; j1++) 
            {
                for (int j2 = 0; j2 < m; j2++) 
                {
                    int maxi = INT_MIN;
                    
                    for (int di = -1; di <= 1; di++) 
                    {
                        for (int dj = -1; dj <= 1; dj++) 
                        {
                            int value;
                            
                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                                value += -1e9;
                            else
                                value += front[j1 + di][j2 + dj];

                            maxi = max(value, maxi);
                        }
                    }
                    
                    curr[j1][j2] = maxi;
                }
            }
            
            front = curr;
        }
        
        return front[0][m - 1];
    }
};