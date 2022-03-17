class Solution {
public:   
    vector<vector<char>> dp;
    
    bool solve(int i, int j, string& s, string& p) 
    {
        if(j == p.length()) 
            return i == s.length();

        if(dp[i][j] != -1) 
            return dp[i][j];
        
        if(p[j] == '*') 
            return dp[i][j] = solve(i, j + 1, s, p) || (i < s.length() && solve(i + 1, j, s, p));
        
        if(i < s.length() && (p[j] == '?'|| s[i] == p[j])) 
            return dp[i][j] = solve(i + 1, j + 1, s, p);
        
        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        dp.resize(s.size() + 1, vector<char>(p.size(), -1));
        
        return solve(0, 0, s, p);    
    }
};