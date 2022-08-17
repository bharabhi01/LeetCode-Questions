class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int ans = 0;
        unordered_map<char, string> hash = {{'a',".-"},{'b', "-..."},{ 'c', "-.-."},{ 'd', "-.."},
                                            {'e', "."},{'f', "..-."},{'g', "--."},{'h', "...."},
                                            {'i', ".."},{'j', ".---"},{'k', "-.-"},{'l', ".-.."},
                                            {'m', "--"},{'n', "-."},{'o', "---"},{'p', ".--."},
                                            {'q', "--.-"},{'r', ".-."},{'s', "..."},{'t', "-"},
                                            {'u', "..-"},{'v', "...-"},{'w', ".--"} ,{'x', "-..-"},
                                            {'y', "-.--"},{'z', "--.."}};
        
        unordered_set<string> uniq_strings;
        
        for (auto& tmp: words)
        {
            string tmp_str;
            
            for (auto& ch: tmp)
            {
                auto node_hash = hash.find(ch);
                if (node_hash != hash.end())
                    tmp_str += node_hash->second;
            }
            
            if (uniq_strings.find(tmp_str) == uniq_strings.end())
                uniq_strings.emplace(tmp_str);
        }
        
        ans = uniq_strings.size();
        
        return ans;
    }
};