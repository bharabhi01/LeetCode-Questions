class Solution {
public:
    const vector<string>pad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"    
    };
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0)
            return {};
        
        vector<string>ans;
        ans.push_back("");
        
        for(auto digit: digits)
        {
            vector<string>temp;
            for(auto candidates: pad[digit - '0'])
            {
                for(auto it: ans)
                    temp.push_back(it + candidates);
            }
            ans.swap(temp);
        }
        
        return ans;
    }
};