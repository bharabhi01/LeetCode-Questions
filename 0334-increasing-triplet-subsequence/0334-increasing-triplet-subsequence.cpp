class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int count1 = INT_MAX, count2 = INT_MAX;
        
        for(int &x : nums) 
        {
            if(x <= count1)
                count1 = x;           
            else if(x <= count2)    
                count2 = x;           
            else            
                return true;   
        }
        
        return false;
    }
};