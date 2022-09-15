class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        
        if(n % 2 != 0) 
            return {};
        
        int maxNum = *max_element(changed.begin(), changed.end());
        vector<int> arr(2 * maxNum + 1);
        
        for(int i = 0; i < n; i++) 
            arr[changed[i]]++;
    
        vector<int> ans;
        
        for(int i = 0; i <= maxNum; i++) 
        {
            if(arr[i]) 
            {
                arr[i]--;
                if(arr[i * 2]) 
                {
                    arr[i * 2]--;
                    ans.push_back(i);
                    
                    if(arr[i]) 
                        i--;
                }
                else
                    return {};
            }
        }
        
        return ans;
    }
};