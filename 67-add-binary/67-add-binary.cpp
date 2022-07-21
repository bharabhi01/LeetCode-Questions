class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size()-1;
        int sum = 0;
        
        while(i >= 0 && j >= 0)
        {
            sum += (a[i] - '0') + (b[j] - '0');
            a[i] = char(sum % 2 + '0');
            sum /= 2;
            i--,j--;
        }
        
        while(i >= 0)
        {
            sum += (a[i] - '0');
            a[i] = char(sum % 2 + '0');
            sum /= 2;
            i--;
        }
    
        while(j >= 0)
        {
            sum += (b[j] - '0');
            a = string(1, char(sum % 2 + '0')) + a;
            sum /= 2;
            j--;
        }
        
        if(sum)
            a = string(1, char(sum + '0')) + a;
        
        return a;
    }
};