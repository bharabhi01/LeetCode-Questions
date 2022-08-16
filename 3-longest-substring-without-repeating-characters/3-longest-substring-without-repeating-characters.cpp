class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0, right = 0, count = 0;
        vector<int>map(256, -1);
        
        while(right < n)
        {
            if(map[s[right]] != -1)
                left = max(map[s[right]] + 1, left);
            
            map[s[right]] = right;
            count = max(count, right - left + 1);
            right++;
        }
        
        return count;
    }
};