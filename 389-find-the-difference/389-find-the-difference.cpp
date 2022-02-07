class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans;
        int S = 0;
        int T = 0;
        
        for(char i: s) S += i;
        for(char i: t) T += i;
        
        ans = T - S;
        
        return ans;
    }
};