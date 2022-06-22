class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < n; i++)
        {
            int low = i + 1, high = n - 1;
            
            while (low < high)
            {
                int curr = nums[i] + nums[low] + nums[high];
                
                if(abs(ans - target) > abs(curr - target))
                    ans = curr;
                
                if(curr < target)
                    low++;
                else
                    high--;
            }
        }
        
        return ans;
    }
};