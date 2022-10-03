class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        
        int posIndex = 0, negIndex = 1;
        
        for(auto num : nums)
        {
            if(num > 0)
            {
                ans[posIndex] = num;
                posIndex += 2;
            }
            
            if(num < 0)
            {
                ans[negIndex] = num;
                negIndex += 2;
            }
        }
        
        return ans;
    }
};