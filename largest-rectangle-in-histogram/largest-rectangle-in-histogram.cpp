class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack <int> st;
        
        int leftSmall[n], rightSmall[n];
        
        for(int i = 0; i < n; i++) 
        {
            while(!st.empty() && heights[i] <= heights[st.top()]) 
            {
                st.pop();
            }
        
            if(st.empty()) leftSmall[i] = 0;

            else leftSmall[i] = st.top() + 1;

            st.push(i);
        } 
        
        while(!st.empty()) st.pop();
        
        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if(st.empty()) rightSmall[i] = n-1;
            else rightSmall[i] = st.top() - 1;

            st.push(i); 
        }
        
        int maxi = 0;
        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
        }
        
        return maxi;
        
    }
};