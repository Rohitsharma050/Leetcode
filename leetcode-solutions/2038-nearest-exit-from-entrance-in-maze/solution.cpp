class Solution {
public:
typedef pair<int,pair<int,int>> P;
bool isvalid(int i,int j,int n ,int m)
{
    return i>=0 && i<n && j<m && j>=0;
}
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n  = maze.size();
        int m =  maze[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int start_i = entrance[0];
        int start_j = entrance[1];
        vis[start_i][start_j] = 1;
        queue<P>q;
        q.push({0,{start_i,start_j}});
        int minsteps = INT_MAX;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r==n-1 || c==m-1 || r==0 || c==0)
            {
                if(steps!=0)
                {
                    minsteps = min(minsteps,steps);
                    return minsteps;
                }
            }
            int dr[]  = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            for(int i = 0;i<4;i++)
            {
                int adjcell_i = r+dr[i];
                int adjcell_j = c +dc[i];
                if(isvalid(adjcell_i,adjcell_j,n,m) && !vis[adjcell_i][adjcell_j] && maze[adjcell_i][adjcell_j]== '.')
                {
                    vis[adjcell_i][adjcell_j] = true;
                    q.push({steps+1,{adjcell_i,adjcell_j}});
                }
            }
            
        }
        return minsteps==INT_MAX?-1:minsteps;
    }
};
