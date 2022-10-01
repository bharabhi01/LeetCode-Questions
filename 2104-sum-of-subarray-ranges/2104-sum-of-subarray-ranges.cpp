class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        
        vector<int> v;
        vector<int> prevMin(n, -1), nextMin(n, n), prevMax(n, -1), nextMax(n, n);

        for(int i = 0; i < n; ++i)
        {
            while(!v.empty() and nums[i] <= nums[v.back()]) 
                v.pop_back();
            
            if(!v.empty()) 
                prevMin[i] = v.back();
            
            v.push_back(i);
        }

        v.clear();

        for(int i = n - 1; i >= 0; --i)
        {
            while(!v.empty() and nums[i] < nums[v.back()]) 
                v.pop_back();
            
            if(!v.empty()) 
                nextMin[i] = v.back();
            
            v.push_back(i);
        }

        v.clear();

        for(int i = 0; i < n; ++i)
        {
            while(!v.empty() and nums[i] >= nums[v.back()]) 
                v.pop_back();
            
            if(!v.empty()) 
                prevMax[i] = v.back();
            
            v.push_back(i);
        }

        v.clear();

        for(int i = n - 1; i >= 0; --i)
        {
            while(!v.empty() and nums[i] > nums[v.back()]) 
                v.pop_back();
            
            if(!v.empty()) 
                nextMax[i] = v.back();
            
            v.push_back(i);
        }

        for(int i = 0; i < n; ++i)
        {
            long long leftMin = i - prevMin[i];
            long long rightMin = nextMin[i] - i;
            long long leftMax = i - prevMax[i];
            long long rightMax = nextMax[i] - i;

            sum += (leftMax * rightMax - leftMin * rightMin) * nums[i];
        }
        
        return sum;
    }
};