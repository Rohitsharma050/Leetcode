class Solution {
public:
void dfs(int node,vector<bool>&vis, vector<vector<int>> &adj,int &temp)
{
    vis[node] = 1;
    for(auto neigh:adj[node])
    {
        if(!vis[neigh])
        {
            temp++;
            dfs(neigh,vis,adj,temp);
        }
    }
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int m = bombs[0].size();
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++)
        {
            int x = bombs[i][0];
            int y = bombs[i][1];
            int r = bombs[i][2];
            for(int j = 0;j<n;j++)
            {
                if(i==j)
                continue;
                int x0 = bombs[j][0];
                int y0 = bombs[j][1];
               long long dist = (long long)(x - x0) * (x - x0) + (long long)(y - y0) * (y - y0);
                if(dist<=(long long)r * r)
                {
                    adj[i].push_back(j);      
                }
            }
        }
       
        int ans = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            vector<bool>vis(n,0);
            int temp = 1;
            if(!vis[i])
            {
                 
                dfs(i,vis,adj,temp);
                ans = max(temp,ans);
            }

        }
        return ans;
    }
};
