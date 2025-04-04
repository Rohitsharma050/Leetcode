class Solution {
public:
bool dfs(int node,vector<bool>&vis, vector<vector<int>> &adj, int dest)
{
    
    if(node==dest)
    return true;
    vis[node] = true;
    for(auto neigh:adj[node])
    {
        if(!vis[neigh])
        {
            if(dfs(neigh,vis,adj,dest)){
                return true;
            }
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);
        for (auto& edge : edges) 
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,0);
        return dfs(source,vis,adj,destination);
    }
};
