class Solution {
public:
    int getLength(vector<int>&a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int>st;
        
        st.insert(getLength(p1, p2));
        st.insert(getLength(p1, p3));
        st.insert(getLength(p1, p4));
        st.insert(getLength(p2, p3));
        st.insert(getLength(p2, p4));
        st.insert(getLength(p3, p4));
        
        return st.size() == 2 && !st.count(0);
    }
};