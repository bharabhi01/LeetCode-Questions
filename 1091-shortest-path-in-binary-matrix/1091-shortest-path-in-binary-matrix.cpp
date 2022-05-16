class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] || grid.back().back()) 
            return -1;
        
        int res = 2, len = 1, maxX = grid[0].size() - 1, maxY = grid.size() - 1;
        queue<pair<int, int>> q1, q2;
        bool isStartTurn = true;

        if (!maxX && !maxY) 
            return 1 - (grid[0][0] << 1);
        
        q1.push({0, 0});
        q2.push({maxX, maxY});
        
        grid[0][0] = -1;
        grid[maxY][maxX] = -2;
        
        while (len) 
        {
            while (len--) 
            {
                auto [cx, cy] = (isStartTurn ? q1 : q2).front();
                (isStartTurn ? q1 : q2).pop();
                for (int x = max(0, cx - 1), lmtX = min(cx + 1, maxX); x <= lmtX; x++) 
                {
                    for (int y = max(0, cy - 1), lmtY = min(cy + 1, maxY); y <= lmtY; y++) 
                    {    
                        if (grid[y][x] == (isStartTurn ? -2 : -1)) 
                            return res;
                        if (!grid[y][x]) 
                        {
                            grid[y][x] = isStartTurn ? -1 : -2;
                            (isStartTurn ? q1 : q2).push({x, y});
                        }
                    }
                }
            }
            
            res++;
            isStartTurn = !isStartTurn;
            len = (isStartTurn ? q1 : q2).size();
        }
        
        return -1;
    }
};