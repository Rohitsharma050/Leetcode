class Solution {
public:
bool isvalid(int i,int j,int n,int m)
{
    return i>=0 && i<n && j>=0 && j<m;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            ans[r][c] = d;
            int nrow[4] = {1,-1,0,0};
            int ncol[4] = {0,0,1,-1};
            for(int k = 0;k<4;k++)
            {
                int row = r+nrow[k];
                int col = c+ncol[k];
                if(isvalid(row,col,n,m) && mat[row][col]==1 && visited[row][col]==0)
                {
                    q.push({{row,col},d+1});
                    visited[row][col]=1;

                }
            }
            
        }
        return ans;
    }
};
