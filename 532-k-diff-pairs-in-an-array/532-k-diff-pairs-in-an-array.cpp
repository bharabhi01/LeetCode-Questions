class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int>mp;
        
        for(auto num: nums)
            mp[num]++;
        
        int count = 0;
        
        if(k > 0)
        {
            for(auto it: mp)
            {
                if(mp.find(it.first + k) != mp.end())
                    count++;
            }
        }
        else
        {
            for(auto it: mp)
            {
                if(it.second > 1)
                    count++;
            }
        }
        
        return count;
    }
};