class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        priority_queue<int, vector<int>, greater<int>> topK;
        
        for(auto& it : nums)
            mp[it]++;
        
        for(auto& it : mp)
        {
            topK.push(it.second);
            
            if(topK.size() > k)
                topK.pop();
        }
        
        vector<int>ans;
        
        for(auto& it : mp)
        {
            if(it.second >= topK.top())
                ans.push_back(it.first);
        }
        
        return ans;
    }
};