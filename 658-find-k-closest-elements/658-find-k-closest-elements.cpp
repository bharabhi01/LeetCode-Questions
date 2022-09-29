class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left, right;
        
        right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        left = right - 1;
        
        while(k--)
        {
            if(right >= arr.size() || (left >= 0 && x - arr[left] <= arr[right] - x))
                left--;
            else 
                right++;
        }
        
        return {arr.begin() + left + 1, arr.begin() + right};
    }
};