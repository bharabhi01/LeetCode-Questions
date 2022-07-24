class Solution {
public:
    int sumOfSquares(int n)
    {
        int sum = 0;
        
        while(n)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {
        if(n <= 0)
            return false;
        
        unordered_set<int> st;
        
        while(st.find(n) == st.end())
        {
            st.insert(n);
            n = sumOfSquares(n);
            
            if(n == 1)
                return true;
        }
        
        return false;
    }
    
};