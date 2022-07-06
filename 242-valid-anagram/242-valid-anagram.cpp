class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>mpp;
        
        if(s == t)
            return true;
        
        if(s.size() != t.size())
            return false;
        
        for(int i = 0; i < s.size(); i++)
        {
            mpp[s[i]]++;
            mpp[t[i]]--;
        }
        
        for(auto it: mpp)
        {
            if(it.second)
                return false;
        }
        
        return true;
    }
};