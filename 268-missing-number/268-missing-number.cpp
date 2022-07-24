class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        int i = 0;
        
        for(int num: nums)
        {
            ans ^= num;
            ans ^= i;
            i++;
        }
        
        return ans;
    }
};