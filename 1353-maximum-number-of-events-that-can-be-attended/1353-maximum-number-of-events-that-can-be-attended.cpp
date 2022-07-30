class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int> > pq;
        
        int maxday = 1;
        
        for(auto& x : events)
            maxday = max(maxday, x[1]);
        
        int day = 1, ans = 0, eid = 0;
        
        while(day <= maxday)
        {    
            if(eid < n and pq.empty())
                day = events[eid][0];
            
            while(eid < n and events[eid][0] <= day)
            {
                pq.push(events[eid][1]);
                eid++;
            }
        
            while(!pq.empty() and pq.top() < day)
                pq.pop();
            
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
            
            day++;
        }
        
        return ans;
    }
};