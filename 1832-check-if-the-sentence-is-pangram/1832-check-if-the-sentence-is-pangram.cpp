class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>alphabets(26, 0);
        
        for(char ch : sentence)
            alphabets[ch - 'a']++;
        
        for(int i = 0; i < 26; i++)
        {
            if(alphabets[i] == 0)
                return false;
        }
        
        return true;
    }
};