class Solution {
public:
    bool is_iso(string a,string b) {
        int m = a.size();
        int n = b.size();
        
        if(m != n)
            return false;
        
        int mp1[256] = {0};
        int mp2[256] = {0};
        
        for(int i = 0; i < n; i++)
        {
            if(mp1[a[i]] == 0 && mp2[b[i]] == 0)
            {
                mp1[a[i]] = b[i];
                mp2[b[i]] = a[i];
            }
            else if(mp1[a[i]] != b[i])
                return false;
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(auto &x : words)
        {
            if(is_iso(x, pattern))
                ans.push_back(x);
        }
        
        return ans;
    }
};