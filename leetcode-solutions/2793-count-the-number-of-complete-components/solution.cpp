class Solution {
public:
void dfs(int node,vector<bool>&vis,vector<vector<int>> &adj,int &v,int &e)
{
    vis[node] = 1;
    v++;
    for(auto neigh:adj[node])
    {
         e++;
        if(!vis[neigh])
        {
            dfs(neigh,vis,adj,v,e);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>parent(n);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
        }
        vector<vector<int>> adj(n);
        for(auto edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        vector<bool>vis(n,0);
        for(int  i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                int v = 0;
                int e = 0;
                dfs(i,vis,adj,v,e);
               // return e;
                int j  = (v*(v-1))/2;
                if(e/2 ==j )
                {
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
