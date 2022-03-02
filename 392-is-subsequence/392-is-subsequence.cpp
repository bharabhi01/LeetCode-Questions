class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLength = s.length();
        int tLength = t.length();
        int j = 0;
        
        for(int i = 0; i < tLength && j < sLength; i++)
        {
            if(s[j] == t[i])
                j++;
        }
        
        return (j == sLength);
    }
};