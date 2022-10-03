class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp,visited;
        
        for(auto num : nums)
            mp[num] = 1;
        
        int ans = 0, count;
        
        for(auto num : nums)
        {
            count = 0;
            
            if(visited[num] == 0 && mp.find(num - 1) == mp.end())
            {
                while(mp.find(num) != mp.end())
                {
                    count++;
                    visited[num] = 1;
                    num++;
                }
            }
            
            ans = max(ans, count);
        }
        
        return ans;
    }
};