// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    vector<int> ans(26,0);
	    vector<int> arr(26,0);
	    
	    for(int i = 0; i < pat.length(); i++)
	        ans[pat[i] - 'a']++;
	    
	    int i=0, j=0, count=0;
	    
	    while(j < txt.length())
	    {
	        arr[txt[j] - 'a']++;
	        
	        if(j - i + 1 < pat.length())
	            j++;
	        else if(j - i + 1 == pat.length())
	        {
	            if(ans == arr) 
	                count++;
	            
	            arr[txt[i] - 'a']--;
	            i++;
	            j++;
	        }
	    }
	    
	    return count;
	}
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends