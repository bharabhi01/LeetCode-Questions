class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);
        int n = s.length(), low = 0, maxLength = 0, max_freq = 0;
        
        for(int i = 0; i < n; i++)
        {
            freq[s[i]-'A']++;
            int curr_freq = freq[s[i] - 'A'];
            
            max_freq = max(max_freq, curr_freq);
            
            while(i - low - max_freq + 1 > k)
            {
                freq[s[low] - 'A']--;
                low++;
            }
            
            maxLength = max(maxLength, i - low + 1); 
        }
        
        return maxLength;
    }
};