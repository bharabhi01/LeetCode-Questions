class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0)
            return 0;
        
        int maxi = nums[0]; // 6, -2
        int mini = nums[0]; // 3
        int maxSoFar = nums[0];
        int maxNow, minNow;
        
        for(int i = 1; i < n; i++)
        {
            maxNow = max(max(maxi * nums[i], mini * nums[i]), nums[i]); // 6, -2
            minNow = min(min(maxi * nums[i], mini * nums[i]), nums[i]); // 3, -6
            
            maxSoFar = max(maxNow, maxSoFar); // 6, 6,
            
            maxi = maxNow; 
            mini = minNow;
        }
        
        return maxSoFar;
    }
};