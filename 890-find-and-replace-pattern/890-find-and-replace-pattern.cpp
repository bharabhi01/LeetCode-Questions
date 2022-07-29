class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(auto x : words)
        {
            if(x.length() == pattern.length())
            {
                ans.push_back(x);
                unordered_map<char,char> mx;
                unordered_map<char,char> mp;
                
                for(int i = 0; i < x.length(); i++)
                {
                    if(mx.find(x[i]) == mx.end() && mp.find(pattern[i]) != mp.end())
                    {
                        ans.pop_back();
                        i = x.length();
                    }
                    else if(mx.find(x[i]) != mx.end() && mp.find(pattern[i]) == mp.end())
                    {
                        ans.pop_back();
                        i = x.length();
                    }
                    else if(mx.find(x[i]) == mx.end() && mp.find(pattern[i]) == mp.end())
                    {
                        mx[x[i]] = pattern[i];
                        mp[pattern[i]] = x[i];
                    }
                    else if(mx[x[i]] != pattern[i] || mp[pattern[i]] != x[i])
                    {
                        ans.pop_back();
                        i = x.length();
                    }
                }
            }
        }
        
        return ans;
    }
};