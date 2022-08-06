class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int days = minutesToTest / minutesToDie;
        int x = days + 1;
        double a = log10(buckets);
        double b = log10(x);
        
        return ceil(a / b);
    }
};