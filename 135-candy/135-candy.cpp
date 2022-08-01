class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        int leftNeighbor[n], rightNeighbor[n];
        
        for(int i = 0; i < n; i++)
            leftNeighbor[i] = rightNeighbor[i] = 1;
        
        for(int i = 1; i < n; i++)
            if(ratings[i] > ratings[i - 1])
                leftNeighbor[i] = leftNeighbor[i - 1] + 1;
        
        for(int i = n - 2; i >= 0; i--)
            if(ratings[i] > ratings[i + 1])
                rightNeighbor[i] = rightNeighbor[i + 1] + 1;
        
        int result[n];
        
        for(int i = 0; i < n; i++)
            result[i] = max(leftNeighbor[i], rightNeighbor[i]);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
            ans += result[i];
        
        return ans;
    }
};