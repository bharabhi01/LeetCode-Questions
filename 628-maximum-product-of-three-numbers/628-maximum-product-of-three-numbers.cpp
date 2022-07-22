class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1, max2, max3, min1, min2, ans = 0, n = nums.size();
        max1 = max2 = max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        
       for(auto num: nums)
       {
           if(num > max1)
           {
               max3 = max2;
               max2 = max1;
               max1 = num;
           }
           else if(num > max2)
           {
               max3 = max2;
               max2 = num;
           }
           else if(num > max3)
               max3 = num;
           
           if(num < min1)
           {
               min2 = min1;
               min1 = num;
           }
           else if(num < min2)
               min2 = num;
        }
        
        if(max1 * max2 * max3 > min1 * min2 * max1)
            ans = max1 * max2 * max3;
        else
            ans = min1 * min2 * max1;
        
        return ans;
    }
};