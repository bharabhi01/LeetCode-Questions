class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        
        for(int i = 0; i < n; i++)
        {
            unordered_map<double,int>mp;
            int duplicate = 0;
            double slope = 0.0;

            for(int j = 0; j < n; j++)
            {
                int x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];
                
                int dy = y2 - y1, dx = x2 - x1;
                
                if(dy == 0 && dx == 0)
                {
                    duplicate++;
                    continue;
                }
                
                if(dx != 0)
                    slope = (dy * 1.0) / dx;
                else
                    slope = INT_MAX;
                
                mp[slope]++;
            }
            
            if(mp.size() == 0)
                res = duplicate;
            else
            {
                for(auto slope: mp)
                    res = max(res, slope.second + duplicate);
            }
        }
        
        return res;
    }
};