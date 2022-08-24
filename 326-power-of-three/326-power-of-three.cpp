class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n)
            return false;
        
        long long int i;
        
        for(i = 1; i < n; i *= 3)
            continue;
        
        return i == n;
    }
};