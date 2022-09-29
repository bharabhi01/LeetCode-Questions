class Solution {
public:
    vector<int>leftArray(vector<int>& heights) {
        int n = heights.size();
        vector<int> left;
        stack<pair<int,int>> s1;
        
        int pseudo_index = -1;
        
        for(int i = 0; i < n;i++)
        {
            if (s1.size() == 0)
                left.push_back(pseudo_index);
            else if (s1.size() > 0 && s1.top().first < heights[i])
                left.push_back(s1.top().second);
            else if (s1.size() > 0 && s1.top().first >= heights[i])
            {
                while(s1.size() > 0 && s1.top().first >= heights[i])
                    s1.pop();
    
                if (s1.size() == 0)
                    left.push_back(pseudo_index);
                else
                    left.push_back(s1.top().second);
            }
            
            s1.push({heights[i], i});
        }
        
        return left;
    }
    
    vector<int>rightArray(vector<int>& heights) {
        int n = heights.size();
        vector<int> right;
        stack<pair<int, int>> s2;
        
        int pseudo_index1 = n;
        
        for(int i = n - 1; i >= 0; i--)
        {
            if (s2.size() == 0)
                right.push_back(pseudo_index1);
            else if (s2.size() > 0 && s2.top().first < heights[i])
                right.push_back(s2.top().second);
            else if (s2.size() > 0 && s2.top().first >= heights[i])
            {
                while(s2.size() > 0 && s2.top().first >= heights[i])
                    s2.pop();
    
                if (s2.size() == 0)
                    right.push_back(pseudo_index1);
                else
                    right.push_back(s2.top().second);
            }
            
            s2.push({heights[i], i});
        }
        
        reverse(right.begin(), right.end());
        
        return right;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left = leftArray(heights);
        vector<int>right = rightArray(heights);
        
        int ans = INT_MIN;
        
        for (long long i = 0; i < n; i++)
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), area = 0;
        
        if(m == 0) 
            return 0;
        
        vector<int>histogram(n, 0);
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    histogram[j] += 1;
                else
                    histogram[j] = 0;
            }
            
            area = max(area, largestRectangleArea(histogram));
        }
        
        return area;
    }
};