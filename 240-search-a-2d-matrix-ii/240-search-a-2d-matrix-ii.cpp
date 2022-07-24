class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = n ? matrix[0].size() : 0;
        int start = 0, last = m - 1; 
        
        while(start < n && last >= 0)
        {
            if(matrix[start][last] == target)
                return true;
            
            matrix[start][last] > target ? last-- : start++;
        }
        
        return false;
    }
};