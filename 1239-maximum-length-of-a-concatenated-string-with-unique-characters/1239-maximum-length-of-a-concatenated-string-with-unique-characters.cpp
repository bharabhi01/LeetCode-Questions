class Solution {
public:
    int length{0};
    
    bool isUnique(string str) {
        unordered_set<char>st;
        
        for(auto it: str) {
            if(st.find(it) != st.end())
                return false;
            
            st.insert(it);
        }
        
        return true;
    }
    
    void checkLength(string str, vector<string>& arr, int i) {
        if(!isUnique(str))
            return;
        
        if(str.length() > length)
            length = str.size();
        
        for(int j = i; j < arr.size(); j++)
            checkLength(str + arr[j], arr, j + 1);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        
        checkLength("", arr, 0);
        
        return length;
    }
};