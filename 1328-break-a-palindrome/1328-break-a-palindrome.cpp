class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size(), count = 1;
        int m = palindrome.length() / 2 - 1;
        
        if(n == 1 || palindrome == "")
            return "";
        
        for(int i = 0; i <= m; i++)
        {
            if(palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                count = 0;
                break;
            }
        }
        
        if(count == 1)
            palindrome[n - 1] = 'b';
        
        return palindrome;
    }
};