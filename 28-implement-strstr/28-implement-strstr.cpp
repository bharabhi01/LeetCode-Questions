class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) 
            return 0;
        
        int n = needle.size();
        bool found = true;
        for (int i = 0; i < haystack.size(); ++i) 
        {
            if (i + n > haystack.size()) 
                break;
            found = true;
            
            for (int j = 0; j < needle.size(); ++j) 
            {
                if (haystack[i + j] != needle[j])  
                {
                    found = false;
                    break;
                }
            }
            
            if (found) 
                return i;
        }
        
        return -1;
    }
};