class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        if(n > m)
            return false;
        
        vector<int>freq(26, 0), curr(26, 0);
        
        for(int i = 0; i < n; i++)
        {
            freq[s1[i] - 'a']++;
            curr[s2[i] - 'a']++;
        }
        
        if(freq == curr)
            return true;
        
        for(int i = n; i < m; i++)
        {
            curr[s2[i - n] - 'a']--;
            curr[s2[i] - 'a']++;
            
            if(freq == curr)
                return true;
        }
        
        return false;
    }
};