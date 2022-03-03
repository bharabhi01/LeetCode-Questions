class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int i = 2, j = 1; i < n; i++)
        {
            if(nums[i] - nums[i - 1] != nums[j] - nums[j - 1])
                j = i;
            
            ans += i - j;
        }
        
        return ans;
    }
};