class Solution {
public:
    vector<int> countdigit(int n) {
        vector<int>v(10, 0);
        while(n != 0)
        {
            int ld = n % 10;
            v[ld]++;
            n /= 10;
        }
        return v;
    }

    bool reorderedPowerOf2(int n) {
        vector<int>v;
        v = countdigit(n);

        for(int i = 0; i <= 30; i++)
        {
            int t = pow(2, i);
            vector<int>m;

            m = countdigit(t);
            
            if(m == v) 
                return true;
        }
        return false;
    }
};