class Solution {
public:
    bool isPowerOfTwo(int n) {
        long x = 1;
        
        if (n == 1)
            return true;
        
        while (n >= x)
        {
            if (x == n)
                return true;
            
            x = x * 2;
        }
        
        return false;
    }
};