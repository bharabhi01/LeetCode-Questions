class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        int i = n - 1, j = 0;
        
        while(i >= 0 && i < n && j >= 0 && j < m)
        {
            if(grid[i][j] < 0)
            {
                count += (m - j);
                i = i - 1;
            }
            else
                j = j + 1;
        }
        
        return count;
    }
};