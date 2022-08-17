class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        int ans;
        
        for(int i = 0; i < n - 1; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};