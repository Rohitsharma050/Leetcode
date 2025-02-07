class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>>grid(n,vector<int>(n,INT_MAX));
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i==j)
                grid[i][j] = 0;   
            }
        }
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            grid[u][v] = w;
            grid[v][u] = w;
        }
        for(int via = 0;via<n;via++)
        {
            for(int i = 0;i<n;i++)
            {
                for(int j  =0;j<n;j++)
                {
                    if(grid[i][via]!=INT_MAX && grid[via][j]!=INT_MAX)
                    {
                        grid[i][j] = min(grid[i][j],grid[i][via]+grid[via][j]);
                    }
                }
            }
        }
        vector<int>neigh(n,0);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]<=k)
                {
                    neigh[i]++;
                }
            }
        }
       
        int index = 0;
        int mini = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            if(neigh[i]<=mini)
            {
                index = i;
                mini = neigh[i];
            }
        }
        return index;
    }
};
