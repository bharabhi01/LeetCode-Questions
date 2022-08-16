class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = x, ans, mid;
        
        while(left <= right)
        {
            mid = (left + right) / 2;
            
            if(mid * mid == x)
                return mid;
            else if((mid * mid) < x)
            {
                left = mid + 1;
                ans = mid;
            }
            else
                right = mid - 1;
        }
        
        return ans;
    }
};