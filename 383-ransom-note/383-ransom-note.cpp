class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int map1[26] = {0};
        int map2[26] = {0};
        
        for(char ch : ransomNote)
            map1[ch - 97]++;
        
        for(char ch : magazine)
            map2[ch - 97]++;
        
        for(int i = 0; i < 26;i++)
            if(map2[i] < map1[i]) 
                return false;
        
        return true;
    }
};