class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>factor;
        factor.push_back(1);
        
        for(int i = 2; i <= n /2; i++)
        {
            if(n % i == 0)
                factor.push_back(i);
        }
        
        factor.push_back(n);
        
        if(k > factor.size())
            return -1;
        
        return factor[k - 1];
    }
};