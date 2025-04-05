class Solution {
public:
void dfs(int node,vector<bool>&vis, vector<vector<pair<int,int>>>&adj,int &ans)
{
    vis[node] =1;
    for(auto neigh:adj[node])
    {
        int adjnode = neigh.first;
        int direct  = neigh.second;
        
        if(!vis[adjnode])
        {
            ans+=direct;
            dfs(adjnode,vis,adj,ans);
        }
    }
}
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge:connections)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        vector<bool>vis(n,0);
        int ans = 0;
        dfs(0,vis,adj,ans);
        return ans;
    }
};
