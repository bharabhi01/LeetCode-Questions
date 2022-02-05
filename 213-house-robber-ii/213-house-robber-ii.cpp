class Solution {
public:
    int maximum(vector<int> &nums) 
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i = 0; i < n; i++)
        {
            int pick = nums[i];
            if(i > 1)
                pick += prev2;
            
            int notPick = prev;
            
            int curr = max(pick, notPick);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;  
        int m = nums.size();
        
        if(m == 1)
            return nums[0];

        for(int i = 0; i < m; i++)
        {
            if(i != 0)
                temp1.push_back(nums[i]);
        
            if(i != m-1)
                temp2.push_back(nums[i]);
        }  
        
        return max(maximum(temp1), maximum(temp2));    
    }
};