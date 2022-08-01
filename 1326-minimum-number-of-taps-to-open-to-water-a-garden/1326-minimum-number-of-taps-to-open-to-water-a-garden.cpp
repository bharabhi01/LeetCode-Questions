class Solution {
public:
   int minTaps(int n, vector<int>& ranges) {
       vector<int> jumps(n + 1, 0);
       int size = ranges.size();
       
       for (int i = 0; i < size; i++) 
       {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
           
            jumps[left] = max(jumps[left], right - left);
       }
       
       int count = 0, curEnd = 0, curFarthest = 0;
       
       for (int i = 0; i < jumps.size() - 1; i++) 
       {
           if (i>curFarthest)
               return -1;
           
           curFarthest = max(curFarthest, i + jumps[i]);
            
           if (i == curEnd) 
           {
               count++;
               curEnd = curFarthest;
           }
       }
       
       return curFarthest >= n ? count : -1;
   }
};