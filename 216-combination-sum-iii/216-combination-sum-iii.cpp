class Solution {
public:
    void helper(int i, int n, int k, vector<vector<int>> &ans, vector<int> &sum) {
        if(n == 0 && k == 0)
        {
            ans.push_back(sum);
            return;
        }
        
        for(int j = i; j <= 10 - k && j <= n; j++)
        {
            sum.push_back(j);
            helper(j + 1, n - j, k - 1, ans, sum);
            sum.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>sum;
        
        helper(1, n, k, ans, sum);
        
        return ans;
    }
};