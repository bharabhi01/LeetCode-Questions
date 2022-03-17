class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        
        int ans = 0, j = 0, n = s.size();
        
        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == '(')
            {
                if(s[i + 1] == ')')
                    ans += 1 << j;
                
                j++;
            }
            else
                j--;
        }
        
        return ans;
    }
};