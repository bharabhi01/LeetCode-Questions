class Solution {
public:
    void helper(int i, int n, int k, vector<int> &com, vector<vector<int>> &ans) {
        if(com.size() == k)
        {
            ans.push_back(com);
            return; 
        }
        
        for(int j = i; j < n + 1; j++)
        {
            com.push_back(j);
            helper(j + 1, n, k, com, ans);
            com.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>com;
        
        helper(1, n, k, com, ans);
        return ans;
    }
};