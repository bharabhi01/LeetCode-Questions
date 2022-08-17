class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_code = {".-", "-..." , "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                                 ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                                 "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
        unordered_set<string> mp;
    
        for(auto word : words) 
        {
            string code = "";
            
            for(auto ch : word)
                code += morse_code[ch - 'a'];
            
            mp.insert(code);
        }

        return mp.size();
    }
};