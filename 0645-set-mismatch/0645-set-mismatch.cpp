class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), i = 0;
        
        while(i < n)
        {
            int correct = nums[i] - 1;
            
            if( nums[i] != nums[correct])
                swap(nums[i], nums[correct]);
            else
                i++;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i + 1 )
            {
                ans.push_back(nums[i]);
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};