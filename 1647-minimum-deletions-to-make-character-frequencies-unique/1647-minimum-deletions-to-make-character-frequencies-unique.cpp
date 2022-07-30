class Solution {
public:
    int minDeletions(string s) {
        int count[26] = {}, ans = 0;
        unordered_set<int>usedCount;
        
        for(char ch : s)
            count[ch - 'a']++;
        
        for(int i = 0; i < 26; i++)
        {
            for(; count[i] > 0 && !usedCount.insert(count[i]).second; count[i]--)
                ans++;
        }
        return ans;
    }
};