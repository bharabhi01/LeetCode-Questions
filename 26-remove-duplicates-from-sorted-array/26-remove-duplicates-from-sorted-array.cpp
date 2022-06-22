class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>mySet;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
            mySet.insert(nums[i]);
        
        int m = mySet.size(), j = 0;
        
        for(int x: mySet)
            nums[j++] = x;
        
        return m;
    }
};