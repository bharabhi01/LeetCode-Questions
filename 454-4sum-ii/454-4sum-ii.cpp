class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // Declare a hashtable.
        unordered_map<int, int>mp;
        
        // Store the length of the array.
        int len = nums1.size();
        
        // Declare an integer which will store the answer.
        int res = 0;
        
        // Now in a loop increment the hashtable at the sum of the pair.
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                mp[nums1[i] + nums2[j]]++; 
            }
        }
        
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                // Check if the negative of the stored sum pair is present in the hashtable or not.
                
                // i.e mp[nums1[i] + nums2[j]] + mp[nums3[k] + nums4[l]] == 0
                
                // But, we don't need 0. We need to find the two tuple.
                
                // Hence, we store the value in the hashtable in the res.
                
                // If such value is present in the hashtable, it will get stored in the res,
                
                // Else, it will get neglected (because it was a 0).
                
                res = res + mp[-(nums3[i] + nums4[j])];
            }
        }
        
        // Return res which contains the two tuples. 
        return res;
    }
};