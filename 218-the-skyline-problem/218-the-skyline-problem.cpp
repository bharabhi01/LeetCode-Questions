class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int, int>> pq;
        vector<int> boundaries; 
        
        for (auto& building : buildings) 
        {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        
        sort(boundaries.begin(), boundaries.end());

        vector<vector<int>> ans;
        int n = buildings.size(), idx = 0;
        
        for (auto& boundary : boundaries) 
        {
            while (idx < n && buildings[idx][0] <= boundary) 
            {
                pq.emplace(buildings[idx][2], buildings[idx][1]);
                idx++;
            }
        
            while (!pq.empty() && pq.top().second <= boundary) 
                pq.pop();

            int maxn = pq.empty() ? 0 : pq.top().first;
            
            if (ans.size() == 0 || maxn != ans.back()[1]) 
                ans.push_back({boundary, maxn});
        }
        
        return ans;
    }
};