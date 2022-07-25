class Solution {
public:
    int firstPos(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        
        while(start <= end) 
        {
            int mid = start + (end - start) / 2;
            
            if(target == nums[mid]) 
            {
                ans = mid;
                end = mid - 1;
            }
            
            if(target < nums[mid])
                end = mid - 1;
            else if(target > nums[mid])
                start = mid + 1;
        }
        
        return ans;
    }
    
    int lastPos(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        
        while(start <= end) 
        {
            int mid = start + (end - start) / 2;
            
            if(target == nums[mid]) 
            {
                ans = mid;
                start = mid + 1;
            }
            
            if(target < nums[mid]) 
                end = mid - 1;
            else if(target > nums[mid])
                start = mid + 1;
        }
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) 
            return {-1, -1};
        
        int first = firstPos(nums, target);
        int last = lastPos(nums, target);
        
        return {first, last};
    }
};
