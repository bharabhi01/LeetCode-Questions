class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n = asteroids.size();
        
        for(auto ast : asteroids) 
        {
            if(ast > 0)
                st.push(ast);
            else
            {
                while(!st.empty() && st.top() > 0 && st.top() < abs(ast))
                    st.pop();
                
                if(st.empty() || st.top() < 0)
                    st.push(ast);
                
                else if(st.top() + ast == 0)
                    st.pop();
            }
        }
        
        int size = st.size();
        vector<int>ans(size, 0);
        
        while(!st.empty())
        {
            ans[--size] = st.top();
            st.pop();
        }
        
        return ans;
    }
};