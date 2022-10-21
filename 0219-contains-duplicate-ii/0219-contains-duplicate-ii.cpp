class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n = nums.size();
            
        for (int i = 0; i < n; i++) 
        {
            if (i > k)
                st.erase(nums[i - k - 1]);
            
            if (!st.insert(nums[i]).second) 
                return true;
        }
        
        return false;
    }
};