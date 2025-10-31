class Solution {
public:
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis)
{
    vis[node] = 1;
    for(auto neigh:adj[node])
    {
        if(!vis[neigh])
        {
            dfs(neigh,adj,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n,0);
        int count = 0;
        vector<vector<int>>adj(n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j); 
                }
            }
        }
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};
