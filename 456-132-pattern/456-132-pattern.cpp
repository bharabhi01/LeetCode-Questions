class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mini = INT_MIN;
        stack<int>st;
        int n = nums.size();
        
        for(int i = n -1; i >= 0; i--)
        {
            if(nums[i] < mini)
                return true;
            else
            {
                while(!st.empty() && nums[i] > st.top())
                {    
                    mini = st.top();
                    st.pop();
                }
            }
            
            st.push(nums[i]);
        }
        
        return false;
    }
};