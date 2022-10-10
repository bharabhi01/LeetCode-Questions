class Solution {
public:
    int myAtoi(string str) {
        int ans = 0, i = 0, sign = 1;
        int n = str.size();
        
        while(i < n && str[i] == ' ')
            i++;
        
        if(str[i] == '-' || str[i] == '+')
        {
            sign = str[i] == '-' ? -1 : 1;
            i++;
        }
        
        while(i < n && (str[i]  >= '0' && str[i] <= '9'))
        {
            int digit = (str[i] - '0') * sign;
            
            if(sign == 1 && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)))
                return INT_MAX;
            
            if(sign == -1 && (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < INT_MIN % 10)))
                return INT_MIN;
            
            ans = ans * 10 + digit;
            i++;
        }
        
        return ans;
    }
};