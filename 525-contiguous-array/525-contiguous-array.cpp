class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Declare a integer to store the size of the array.
        int n = nums.size();
        
        // Declare a variable to store the sum of the array.
        int sum = 0;
        
        int longCont = 0;
        
        // Declare a map to store the sum and index of the array.
        unordered_map<int, int>mp;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
                sum += 1;
            
            else if(nums[i] == 0)
                sum -= 1;
            
            if(sum == 0)
            {
                // Everytime sum becomes zero, we know all the elements from begining of array have been                        neutralized.
                
                // Meaning we have got equal number of ones and zeroes.
                
                // Let this occurs at index i, so sum = i+1 ('coz w're dealing with indices).
                
                longCont = max(longCont, i + 1);
            }
            
            if(mp.find(sum) != mp.end())
            {
                longCont = max(longCont, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        
        return longCont;
    }
};