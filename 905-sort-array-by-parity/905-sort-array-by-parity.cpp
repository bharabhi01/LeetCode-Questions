class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, n = nums.size();
        
        for(int j = 0; j < n; j++)
        {
            if(nums[j] % 2 == 0)
                swap(nums[i++], nums[j]);
        }
        
        return nums;
    }
};