class Solution {
public:
bool isvalid(int i,int j,int n,int m)
{
    return i>=0 && i<n && j>=0 && j<m;
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        int ans  =0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]='2';
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        int nrow[4] ={-1,0,1,0};
                        int ncol[4] = {0,1,0,-1};
                        for(int k = 0;k<4;k++)
                        {
                            int row = r+nrow[k];
                            int col = c+ncol[k];
                            if(isvalid(row,col,n,m) && grid[row][col]=='1')
                            {
                                q.push({row,col});
                                grid[row][col]='2';
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};
