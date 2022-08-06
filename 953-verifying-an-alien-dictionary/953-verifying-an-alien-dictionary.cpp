class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int>mp;
        
        for(int i = 0; i < order.size(); i++)
            mp[order[i]] = i;
        
        for(auto& word : words)
            for(auto& ch : word)
                ch = mp[ch];
        
        return is_sorted(words.begin(), words.end());
    }
};