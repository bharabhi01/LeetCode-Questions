class Solution {
public:
    int findWays(vector<int> &num, int tar)
    {	
        int n = num.size();
        vector<int>prev(tar + 1, 0), curr(tar + 1, 0);

        if(num[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if(num[0] != 0 && num[0] <= tar)
            prev[num[0]] = 1;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= tar; j++)
            {
                int notPick = prev[j];

                int pick = 0;
                if(num[i] <= j)
                    pick = prev[j - num[i]];

                curr[j] = (pick + notPick);
            }

            prev = curr;
        }

        return prev[tar];
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        int totSum = 0;

        for(auto &it: arr)
            totSum += it;

        if(totSum - d < 0 || (totSum - d) % 2)
            return false;

        return findWays(arr, (totSum - d) / 2); 
    }

    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};