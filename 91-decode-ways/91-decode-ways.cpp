class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int curr = 0, nx1 = 1, nx2 = 0;
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '0') 
                curr = 0; 
            else
            {
                int res = nx1;
                
                if(i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) 
                    res += nx2;
                
                curr = res;
            }
            
            nx2 = nx1;
            nx1 = curr;
        }
        
        return curr;
    }
};