class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int length = 0, tail = n - 1;
        
        while(tail >= 0 && s[tail] == ' ')
            tail--;
        
        while(tail >= 0 && s[tail] != ' ')
        {
            length++;
            tail--;
        }
        
        return length;
    }
};