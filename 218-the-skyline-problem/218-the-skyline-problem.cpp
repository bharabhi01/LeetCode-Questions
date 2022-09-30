class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> heights;
        
        for(auto it : buildings)
        {
            heights.push_back({it[0],-it[2]});
            heights.push_back({it[1], it[2]});
        }
        
        sort(heights.begin(), heights.end());
        
        vector<vector<int>> ans;
        
        multiset<int, greater<int>> ms;
        ms.insert(0);
		
        int preMax = 0;
        
        for(auto it : heights)
        {
            if(it.second < 0)
                ms.insert(-it.second);
			
            else
                ms.erase(ms.find(it.second));
            
            int curMax = *(ms.begin());
            
            if(curMax != preMax)
            {
                ans.push_back({it.first, curMax});
                preMax = curMax;
            }
        }
        
        return ans;
    }
};