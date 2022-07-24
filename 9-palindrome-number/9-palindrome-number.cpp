class Solution {
public:
    bool isPalindrome(int x) {
        long long ans = x;
        long long rev = 0;
        
        while(x > 0)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        
        if(rev == ans)
            return true;
        else
            return false;
    }
};