class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words[0].length();
        unordered_map<string, int> available;
        
        for(string w : words)
            available[w]++;
        
        unordered_map<string, int> used;
        vector<int> matches;
        
        for(int offset = 0; offset < n; ++offset)
        {
            used.clear();
            int start = offset;
            int end = start + n; 
            
            while(start + n * words.size() <= s.length() && end <= s.length())
            {
                string k = s.substr(end - n, n);
                
                if(available.find(k) == available.end())
                {
                    used.clear();
                    start = end;
                    end = start + n;
                }
                else
                {
                    used[k]++;
                    while(used[k] > available[k])
                    {
                        used[s.substr(start, n)]--;
                        start += n;
                    }
                    
                    if(end - start == words.size() * n)
                        matches.push_back(start);
                    
                    end += n;
                } 
            }
        }
        
        return matches;
    }
};