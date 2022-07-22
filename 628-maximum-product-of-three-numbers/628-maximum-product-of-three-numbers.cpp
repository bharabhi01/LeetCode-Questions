class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int last3 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int first3 = nums[0] * nums[1] * nums[n - 1];
        
        return last3 > first3 ? last3 : first3;
    }
};