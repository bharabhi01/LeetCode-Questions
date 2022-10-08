class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int closest = INT_MAX >> 2;
        int N = nums.size();
        
        for (int i = 0; i < N - 2; ++i) 
        {
            if (nums[i] + nums[N - 2] + nums[N - 1] < target) 
            {
                int sum = nums[i] + nums[N - 2] + nums[N - 1];
                
                if (abs(target - sum) <  abs(target - closest)) 
                    closest = sum;
            
                continue;
            }
            
            if (nums[i] + nums[i + 1] + nums[i + 2] > target) 
            {
                int sum = nums[i] + nums[i + 1] + nums[i + 2];
                
                if (abs(target - sum) <  abs(target - closest)) 
                    closest = sum;
            
                return closest;
            }
            
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            
            int j = i + 1;
            int k = N - 1;
            
            while (j < k) 
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                {
                    ++j;
                    continue;
                }
                
                if (k < N - 1 && nums[k] == nums[k + 1]) 
                {
                    --k;
                    continue;
                }
                
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == target) 
                    return target;
                
                if (abs(target - sum) <  abs(target - closest)) 
                    closest = sum;
            
                if (sum < target) 
                    j++;
                
                if (sum > target) 
                    k--;
            }
        }
        
        return closest;
    }
};