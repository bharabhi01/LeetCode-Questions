class Solution {
public:
    static const bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] != b[0])
            return a[0] < b[0];
        
        return a[1] < b[1];
    }
    
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), comp);
        
        int n = events.size(), ans = 0, i = 0;
        multiset<int>endDays;
        
        for(int j = 1; j <= 100000; j++)
        {
            while(!endDays.empty() && *(endDays.begin()) < j)
                endDays.erase(endDays.begin());
            
            while(i < n && events[i][0] == j)
            {
                endDays.insert(events[i][1]);
                i++;
            }
            
            if(endDays.size() > 0)
            {
                ans++;
                endDays.erase(endDays.begin());
            }
        }
        
        return ans;
    }
};