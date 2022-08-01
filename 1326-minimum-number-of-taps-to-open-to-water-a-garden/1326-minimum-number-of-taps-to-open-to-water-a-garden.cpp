class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n + 1, -1);
        
        for(int i = 0; i <= n; ++i) 
        {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            
            jumps[start] = max(jumps[start], end - start);
        }
        
        int currEnd = 0, farthest = 0, count = 0;
        
        for(int i = 0; i < n; ++i) 
        {
            if(i > farthest) 
                return -1;
            
            farthest = max(farthest, i + jumps[i]);
            
            if(i == currEnd) 
            {
                count++;
                currEnd = farthest;
            }
        }
        
        return farthest >= n ? count : -1;
    }
};