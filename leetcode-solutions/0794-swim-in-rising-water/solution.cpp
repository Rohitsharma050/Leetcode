class Solution {
public:
typedef pair<int,pair<int,int>>P;
bool isvalid(int i, int j, int n, int m) {
    return i < n && i >= 0 && j < m && j >= 0;
}
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int t = 0;
        pq.push({t,{0,0}});
        vis[0][0] = 1;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int r = it.second.first;
            int c = it.second.second;
            int currtime = it.first;
            t = max(t,grid[r][c]);
            if(r==n-1 && c==m-1)
            return t;
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            for(int i = 0;i<4;i++)
            {
                int newr = r+dr[i];
                int newc = c+dc[i];
                if(isvalid(newr,newc,n,m) && !vis[newr][newc])
                {
                   pq.push({grid[newr][newc],{newr,newc}});
                   vis[newr][newc] = 1;
                }
            }

        }
        return t;
    }
};
