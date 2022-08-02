class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        
        while(left < right)
        {
            while(left < right && !isalnum(s[left]))
                left++;
            
            while(left < right && !isalnum(s[right]))
                right--;
            
            while(tolower(s[left++]) != tolower(s[right--]))
                return false;
        }
        
        return true;
    }
};