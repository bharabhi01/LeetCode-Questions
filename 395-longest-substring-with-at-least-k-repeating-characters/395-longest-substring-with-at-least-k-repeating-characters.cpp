class Solution {
public:
    int helper(string& s, int start, int end, int k) {
        if(end < k)
            return 0;
        
        int freq[26] = {0};
        for(int i = start; i < end; i++)
            freq[s[i] - 'a']++;
        
        for(int mid = start; mid < end; mid++)
        {
            if(freq[s[mid] - 'a'] >= k)
                continue;
            
            int midNext = mid + 1;
            
            while(midNext < end && freq[s[midNext] - 'a'] < k)
                midNext++;
            
            return max(helper(s, start, mid, k), helper(s, midNext, end, k));
        }
        
        return (end - start);
    }
    
    int longestSubstring(string s, int k) {
        int n = s.size();
        
        return helper(s, 0, n, k);    
    }
};