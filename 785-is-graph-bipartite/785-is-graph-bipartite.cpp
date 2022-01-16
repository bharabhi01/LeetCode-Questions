class Solution {
public:
    bool isBip(int node, int color[], vector<vector<int>>& graph)
    {
        queue<int>q;
        q.push(node);
        color[node] = 1;
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            
            for(auto it: graph[a])
            {
                if(color[it] == -1)
                {
                    color[it] = 1 - color[a];
                    q.push(it);
                }
                else if(color[it] == color[a])
                    return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        
        memset(color, -1, sizeof color);
        
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
                if(!isBip(i, color, graph))
                    return false;
        }
        
        return true;
    }
};