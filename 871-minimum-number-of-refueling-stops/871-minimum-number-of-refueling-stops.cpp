class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i = 0, stops;
        priority_queue<int> pq;
            
        for (stops = 0; startFuel < target; stops++) 
        {
            while (i < stations.size() && stations[i][0] <= startFuel)
                pq.push(stations[i++][1]);
            
            if (pq.empty()) 
                return -1;
            
            startFuel += pq.top(); 
            pq.pop();
        }
            
        return stops;
    }
};