class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s == t)
            return true;
        
        if(s.size() != t.size())
            return false;
        
        int mpp[26] = {};
        
        for(int i = 0; i < s.size(); i++)
        {
            mpp[s[i] - 'a']++;
            mpp[t[i] - 'a']--;
        }
        
        for(int i = 0; i < 26; i++)
        {
            if(mpp[i])
                return false;
        }
        
        return true;
    }
};