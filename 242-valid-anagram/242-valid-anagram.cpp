class Solution {
public:
    bool isAnagram(string s, string t) {
        int maps[29] = {0, };
        
        for(auto c : s) 
            maps[c-'a']++;
            
        for(auto c : t) {
            if(maps[c-'a'] == 0) 
                return false;
            maps[c-'a']--;
        }
        
        for(auto map : maps) {
            if(map > 0) 
                return false;
        }
        
        return true;
    }
};