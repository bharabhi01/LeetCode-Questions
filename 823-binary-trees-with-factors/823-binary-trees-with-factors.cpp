class Solution {
public:
    int mod= 1e9 + 7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        int sum = 1;
        unordered_map<int, long> mp;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]] = 1;
        
        for(int i = 1; i < n; i++)
        {
            double x = sqrt(arr[i]);
            
            for(int j = 0; j < i && arr[j] <= x; j++)
            {
                if(arr[i] % arr[j] == 0)
                {
                    if(arr[j] == arr[i] / arr[j])
                        mp[arr[i]] += 1 * mp[arr[j]] * mp[arr[j]];
                    else if(mp.find(arr[i] / arr[j]) != mp.end())
                        mp[arr[i]] += 2 * mp[arr[j]] * mp[arr[i] / arr[j]];
                }
            }
            sum = (sum + mp[arr[i]]) % mod;
        }
    
        return sum;
    }
};