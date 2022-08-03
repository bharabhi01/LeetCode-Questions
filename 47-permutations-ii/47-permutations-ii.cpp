class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> nums, int i, int j) {    
        if(i == j - 1)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int k = i; k < j; k++)
        {
            if(i != k && nums[i] == nums[k])
                continue;
            
            swap(nums[i], nums[k]);
            helper(ans, nums, i + 1, j);
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        
        helper(ans, nums, 0, n);
        
        return ans;
    }
};