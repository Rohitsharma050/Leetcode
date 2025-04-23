// class Solution {
// public:
// int solve(int i,int prevj,int n,vector<vector<int>>& grid)
// {
//     if(i==n)
//     return 0;
//     int minvalue = INT_MAX;
//     for(int j = 0;j<n;j++)
//     {
//         if(j!=prevj)
//         minvalue = min(minvalue,grid[i][j]+solve(i+1,j,n,grid));
//     }
//     return minvalue;
// }
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         return solve(0,-1,n,grid);
//     }
// };
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        //create dp of same size;
        vector<int>prev(n);
        vector<int>curr(n);
        //fill 1st row of grid in dp
        for(int i = 0;i<n;i++)
        {
           prev[i] = grid[0][i];
        }
        //check  from where index should start
        for(int i=1;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {

                //do the same thing already done in memoization 
                int ans = INT_MAX;
                for(int k =0;k<n;k++)
                {
                    if(j!=k)
                    ans = min(ans,prev[k]+grid[i][j]);
                }
                curr[j]=ans;
            }
            prev = curr;
        }
        int res = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            res  = min(res,prev[i]);
        }
        return res;
    }
};
