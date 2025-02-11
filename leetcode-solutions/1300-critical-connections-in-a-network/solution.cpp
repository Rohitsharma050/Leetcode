class Solution {
public:
int timer = 1;
void dfs(int node,int parent, vector<vector<int>>&adj,vector<int>&low,vector<int>&intime, vector<bool>&vis, vector<vector<int>> &bridges)
{
    vis[node]=true;
    low[node] = intime[node] = timer;
    timer++;
    for(auto adjNode:adj[node])
    {   if(adjNode==parent)
        continue;
        if(vis[adjNode]==0)
        {
            dfs(adjNode,node,adj,low,intime,vis,bridges);
            low[node] = min(low[node],low[adjNode]);
            if(low[adjNode]>intime[node])
            {
                bridges.push_back({adjNode,node});
            }
        }
        else
        {
            low[node]=min(low[node],low[adjNode]);
        }

    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections)
        {
            int u=it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,0);
        vector<int>low(n,0);
        vector<int>intime(n,0);
        vector<vector<int>> bridges;
        dfs(0,-1,adj,low,intime,vis,bridges);
        return bridges;

    }
};
