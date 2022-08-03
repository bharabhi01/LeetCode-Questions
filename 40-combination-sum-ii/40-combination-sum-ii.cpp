class Solution {
public:
    void helper(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &sum, int i, int target) {
        if(target == 0)
        {
            ans.push_back(sum);
            return;
        }

        for(int j = i; j < candidates.size(); j++)
        {
            if(j > i && candidates[j] == candidates[j - 1])
                continue;
            
            if(candidates[j] > target)
                break;
            
                sum.push_back(candidates[j]);
                helper(candidates, ans, sum, j + 1, target - candidates[j]);
                sum.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>sum;
        
        helper(candidates, ans, sum, 0, target);
        
        return ans;
    }
};