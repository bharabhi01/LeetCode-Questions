class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>prev(k + 1, 0), curr(k + 1, 0);
    
    prev[0] = curr[0] = true;
    
    if(arr[0] <= k)
        prev[arr[0]] = true;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            bool notTake = prev[j];
    
    		bool take = false;
    		if(j >= arr[i])
        		take = prev[j - arr[i]];
    
    		curr[j] = (take) or (notTake);
        }
        
        prev = curr;
    }
    
        return prev[k];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++)
            sum += nums[i];
        
        if(sum % 2)
            return false;
        
        int k = sum / 2;
        
        return subsetSumToK(n, k, nums);
    }
};