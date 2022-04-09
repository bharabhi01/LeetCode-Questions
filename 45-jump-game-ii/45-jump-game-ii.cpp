class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, ans = 0;
        
        while(right < n - 1)
        {
            int farthest = 0;
            
            for(int i = left; i < right + 1; i++)
                farthest = max(farthest, nums[i] + i);
            
            left = right + 1;
            right = farthest;
            
            ans += 1;
        }
        
        return ans;
    }
};