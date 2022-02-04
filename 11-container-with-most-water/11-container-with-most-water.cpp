class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        
        int maxArea = 0;
        
        while(left < right)
        {
            int leftHeight = height[left];
            int rightHeight = height[right];
            
            maxArea = max(maxArea, (right - left) * min(leftHeight, rightHeight));
            
            if(leftHeight < rightHeight)
                left++;
            else
                right--;
        }
        
        return maxArea;
    }
};