class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty() || needle.size() > haystack.size())
            return -1;
        
        int j = 0;
        
        for (int i = 0; i < haystack.size(); ++i)
        {
            if (needle[j] == haystack[i])
            {
                j++;
                if(j == needle.size())
                    return i - needle.length() + 1;
            }
            else 
            {
                i -= j;
                j = 0;
            }
        }       
        return -1;
    }
};