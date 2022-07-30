class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int dp1[26];
        fill(dp1, dp1 + 26, 0);
        vector<string>ans;
        
        for(int i = 0; i < words2.size(); i++) 
        {
            int dp[26];
            fill(dp, dp + 26, 0);
            
            for(int j = 0; j < words2[i].length(); j++)
                dp[words2[i][j] - 'a']++;
            
            for(int j = 0;j < 26; j++)
                dp1[j] = max(dp1[j], dp[j]);
        }
        
        for(int i = 0; i < words1.size(); i++) 
        {
            int dp[26];
            fill(dp, dp + 26,0);
            
            for(int j = 0; j < words1[i].length(); j++)
                dp[words1[i][j] - 'a']++;
            
            bool found = true;
            
            for(int j = 0; j < 26; j++) 
            {
                if(dp1[j] > dp[j]) 
                {
                    found = false;
                    break;
                }
            }
            
            if(found)
                ans.push_back(words1[i]);
        }
        
        return ans;
    }
};