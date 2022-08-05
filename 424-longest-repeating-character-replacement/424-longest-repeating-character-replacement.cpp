class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>count(26, 0);
        int n = s.length(), start = 0, maxCount = 0, ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            count[s[i] - 'A']++;
            
            if(maxCount < count[s[i] - 'A'])
                maxCount = count[s[i] - 'A'];
            
            while(i - start - maxCount + 1 > k)
            {
                count[s[start] - 'A']--;
                start++;
                
                for(int j = 0; j < 26; j++)
                    if(maxCount < count[j])
                        maxCount = count[j];
            }
            
            ans = max(ans, i - start + 1);
        }
        
        return ans;
    }
};