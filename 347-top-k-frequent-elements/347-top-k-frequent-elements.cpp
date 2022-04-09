class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        priority_queue<int, vector<int>, greater<int>>maxK;
        
        for(auto i: nums)
            mp[i]++;
                
        for(auto &it: mp)
        {
            maxK.push(it.second);
            
            while(maxK.size() > k)
                maxK.pop();
        }
        
        vector<int>ans;
        
        for(auto &j: mp)
        {
            if(j.second >= maxK.top())
                ans.push_back(j.first);
        }
    
        return ans;
    }
};