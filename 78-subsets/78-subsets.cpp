class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>sub;
        
        subsets(nums, 0, sub, ans, n);
        
        return ans;
    }
    
    void subsets(vector<int> &nums, int i, vector<int> &sub, vector<vector<int>> &ans, int n)
    {
        ans.push_back(sub);
        
        for(int j = i; j < n; j++)
        {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, ans, n);
            sub.pop_back();
        }
    }
};