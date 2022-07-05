class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty() == true)
            return 0;

        sort(nums.begin(), nums.end());
        vector<int>res;
        res.push_back(1);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] + 1 == nums[i])
                res.back()++;
            else if(nums[i - 1] + 1 < nums[i])
                res.push_back(1);
        }

        sort(res.begin(), res.end());
        
        return res.back();

    }
};