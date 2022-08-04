class Solution {
public:
    bool canPart(vector<int>&nums, int bucketSum, int targetSum, int k, int start, vector<bool>&visited) {
        if(k == 1)
            return true;
        
        if(start >= nums.size()) 
           return false;
        
        if(bucketSum == targetSum)
                return canPart(nums, 0, targetSum, k - 1, 0, visited);

        for(int i = start; i < nums.size(); i++)
        {
            if(visited[i] || nums[i] + bucketSum > targetSum)
                continue;
            
            visited[i] = true;
            
            if(canPart(nums, bucketSum + nums[i], targetSum, k, i + 1, visited))
                return true;
            
            visited[i] = false;
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<bool>visited(nums.size(), false);
        
        if(sum % k != 0)
            return false;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        return canPart(nums, 0, sum / k, k, 0, visited);
    }
};