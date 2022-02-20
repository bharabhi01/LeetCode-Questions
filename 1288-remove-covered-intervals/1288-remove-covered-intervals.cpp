class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        int num1 = intervals[0][0];
        int num2 = intervals[0][1];
        
        int ans = 1;
        
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] > num1 && intervals[i][1] > num2)
            {
                ans++;
            }
            
            if(intervals[i][1] > num2)
            {
                num1 = intervals[i][0];
                num2 = intervals[i][1];
            }
        }
        
        return ans;
    }
};