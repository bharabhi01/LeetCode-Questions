class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), ret = 0;
        
        for(int i1 = 0; i1 < m; ++i1) 
        {
            int sums[100] = {0};
            
            for(int i2 = i1; i2 < m; ++i2) 
            {
                for(int j = 0; j < n; ++j)
                    sums[j] += matrix[i2][j];
                
                for(int j = 0; j < n; ++j) 
                {
                    int sum = 0;
                    for (int k = j; k < n; ++k)
                        if (target == (sum = sum + sums[k]))
                            ret++;
                }
            }
        }
        
        return ret;
    }
};