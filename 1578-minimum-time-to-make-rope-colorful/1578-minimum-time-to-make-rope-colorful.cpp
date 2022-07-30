class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n = colors.length();
        int i = 0;
        int cost = 0;
        
        while(i < (n - 1))
        {
            if(colors[i] == colors[i + 1])
            {
                int sum = time[i];
                int ma = time[i];
                i++;
                
                while(i < n && colors[i] == colors[i - 1])
                {
                    ma = max(ma, time[i]);
                    sum += time[i];
                    i++;
                }
                
                cost += (sum - ma);
            }
            else
                i++;
        }
    
        return cost;
    }
};