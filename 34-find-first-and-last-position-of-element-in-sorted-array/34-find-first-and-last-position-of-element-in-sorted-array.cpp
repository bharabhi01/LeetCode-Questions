class Solution {
public:
    int binarySearch(vector<int>& nums, int target, string find)
    {
        int n = nums.size();
        int start = 0, last = n - 1, mid, ans = -1;
        
        while(start <= last)
        {
            mid = (start + last) / 2;
            
            if(nums[mid] == target)
            {
                ans = mid;
                (find == "First") ? last = mid - 1 : start = mid + 1;
            }
            else if(nums[mid] > target)
                last = mid - 1;
            else 
                start = mid + 1;
        }
        
        return ans;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
       return {binarySearch(nums, target, "First"), binarySearch(nums, target, "Last")};
    }
};