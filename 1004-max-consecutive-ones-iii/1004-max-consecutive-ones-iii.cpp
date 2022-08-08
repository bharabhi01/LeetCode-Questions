class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), countZeros = 0, ans = INT_MIN;
        int windowStart = 0, windowEnd = 0;
        
        while(windowEnd < n)
        {
            if(nums[windowEnd] == 0)
                countZeros++;
            
            while(countZeros > k)
            {
                if(nums[windowStart] == 0)
                    countZeros--;
                
                windowStart++;
            }
            
            ans = max(ans, windowEnd - windowStart + 1);
            
            windowEnd++;
        }
        
        return ans;
    }
};