class Solution {

   public:
    vector<vector<int>> ans;
    vector<vector<int>> graph;
    vector<int> tm;
    vector<int> low;
    vector<bool> vis;
    int time=0;
    void dfs(int node,int parent)
    {
        tm[node]=low[node]=time++;
        vis[node]=true;
        for(int &x:graph[node])
        {
            if(parent==x)continue;
            if(vis[x]==false)
            {
                dfs(x,node);
                low[node]=min(low[node],low[x]);
                if(tm[node]<low[x])
                    ans.push_back({node,x});
            }
            else 
                low[node]=min(low[node], tm[x]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        vis.resize(n,false);
        low.resize(n,0);
        tm.resize(n,0);
        for(auto &x:connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
                dfs(i,i);
        }
        return ans;
    }
};