class Solution {
public:
    int myAtoi(string s) {
        bool isNegative = false, flag = false;
		long result = 0;
        
		for(char c: s) 
        {
			if(c == ' ' and !flag) 
				continue;
		
			if(c == '-' and !flag) 
            {
				isNegative = true;
				flag = true;
				continue;
			}
            
			if((c == '+') and !flag) 
            {
				flag = true;
				continue;
			}
            
			if(c < '0' or c > '9') 
				break;
			
			result = (result ? result * 10 : result) + (c - '0');
			
            if(isNegative and result > pow(2, 31)) 
				result = pow(2, 31);
			
			if(!isNegative and result > pow(2, 31) - 1) 
				result = pow(2, 31) - 1;
			
			flag = true;
		}
        
		if(isNegative) 
			result *= -1;
		
		return result;
    }
};