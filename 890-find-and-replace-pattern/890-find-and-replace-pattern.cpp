class Solution {
public:
    string getPattern(string pattern) {
        string ans;
        int j = 0, m = pattern.size();
        
        map<char, char>mp;
        
        for(int i = 0; i < m; i++)
        {
            if(mp.find(pattern[i]) == mp.end())
            {
                mp[pattern[i]] = 'a' + j;
                j++;
            }
            ans.push_back(mp[pattern[i]]);
        }
        
        return ans;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string pat = getPattern(pattern);
        vector<string>ans;
        int n = words.size();
        
        for(int i = 0; i < n; i++)
        {
            string p = getPattern(words[i]);
            
            if(p == pat)
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};