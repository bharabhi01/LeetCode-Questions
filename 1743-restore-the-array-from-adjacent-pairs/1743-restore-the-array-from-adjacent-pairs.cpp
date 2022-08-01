class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &mp, unordered_set<int> &visited, vector<int> &ans, int head) {
        if(visited.find(head) != visited.end())
            return;
        
        ans.push_back(head);
        visited.insert(head);
        
        for(auto it : mp[head])
            dfs(mp, visited, ans, it);
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>>mp;
        
        for(auto it : adjacentPairs)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        
        int head;
        for(auto it : mp)
            if(it.second.size() == 1)
                head = it.first;
        
        vector<int>ans;
        unordered_set<int>visited;
        
        dfs(mp, visited, ans, head);
        
        return ans;    
    }
};