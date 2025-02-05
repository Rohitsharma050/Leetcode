class Solution {
public:
bool valid(int r,int c,int n,int m)
{
    if(r>=0 && r<n && c>=0 && c<m)
    return true;
    return false;
}
typedef pair<int,pair<int,int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1 && grid[0][0]==0)
        return 1;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({1,{0,0}});
        dist[0][0] = 1;
         if (grid[0][0] == 1 || grid[n-1][m-1] == 1) 
            return -1;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int di = it.first;
            int r = it.second.first;
            int c = it.second.second;
            int row[8] = {-1,0,1,0,-1,1,1,-1};
            int col[8]  ={0,1,0,-1,1,1,-1,-1};
            for(int i = 0;i<8;i++)
            {
                int newrow = r+row[i];
                int newcol = c+col[i];
                if(valid(newrow,newcol,n,m) && grid[newrow][newcol]==0 && dist[newrow][newcol] == INT_MAX)
                {
                    if(1+di<dist[newrow][newcol])
                    {
                        dist[newrow][newcol] = 1+di;
                        pq.push({1+di,{newrow,newcol}});
                    }

                }
            }


        }
        if(dist[n-1][m-1]==INT_MAX)
        return -1;
        return dist[n-1][m-1];
    }
};
