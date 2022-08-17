class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int first = 0, last = n - 1;
        
        while(first <= last)
        {
            int mid = (first + last) / 2;
            
            if(arr[mid] < arr[mid + 1])
                first = mid + 1;
            else
                last = mid - 1;
        }
        
        return first;
    }
};