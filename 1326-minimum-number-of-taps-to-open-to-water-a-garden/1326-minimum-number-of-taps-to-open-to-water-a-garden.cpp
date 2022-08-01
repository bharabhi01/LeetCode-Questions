class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int size = ranges.size();
        int min = 0, reach = 0, taps = 0;
        
        while(reach < n)
        {
            for(int i = 0; i < size; i++)
            {
                if(i - ranges[i] <= min && i + ranges[i] > reach)
                    reach = i + ranges[i];
            }
        
            if(min == reach)
                return -1;
        
            taps++;
            min = reach;
        }
        
        return taps;
    }
};