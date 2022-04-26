class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<int>visited(n, false), cost(n, INT_MAX);
        
        auto update_cost = [&](int x, int y)
        {
            for(int i = 0; i < n; i++)
            {
                if(visited[i])
                    continue;
                
                int xi = points[i][0], yi = points[i][1];
                
                cost[i] = min(cost[i], manhattan(x, y, xi, yi));
            }
        };

        visited[0] = true;
        
        cost[0] = 0;
        
        update_cost(points[0][0], points[0][1]);
        
        int ans = 0;
        
        for (int i = 1; i < n; i++) 
        {
            int j = -1;
            for (int k = 0; k < n; k++) 
            {
                if (visited[k]) 
                    continue;
                
                if (j == -1 || cost[j] > cost[k]) 
                    j = k;
            }
            
            ans += cost[j];
            visited[j] = true;
            update_cost(points[j][0], points[j][1]);
        }
        
        return ans;
    }
    
private:
    int manhattan(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};