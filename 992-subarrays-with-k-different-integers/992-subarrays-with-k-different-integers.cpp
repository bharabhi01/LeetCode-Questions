class Solution {
public:
    int atMost(vector<int>& nums, int k, int n) {
        int count = 0, start = 0, end = 0;
        unordered_map<int, int>mp;
        
        while(end < n)
        {
            if(mp.find(nums[end]) == mp.end())
                mp[nums[end]] = 1;
            else
                mp[nums[end]]++;
            
            while(mp.size() > k)
            {
                mp[nums[start]]--;
                
                if(mp[nums[start]] == 0)
                    mp.erase(nums[start]);
                
                start++;
            }
            
            count += end - start + 1;
            end++;
        }
        
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return atMost(nums, k, n) - atMost(nums, k - 1, n);
    }
};