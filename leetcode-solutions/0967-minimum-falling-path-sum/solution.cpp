//Memoization
// class Solution {
// public:
// int solve(int i,int j,int n,vector<vector<int>>& grid)
// {
//     if(j<0 || j>n-1)
//     {
//         return INT_MAX;
//     }
//     if(i==n-1)
//     return grid[i][j];
    
//     int left = solve(i+1,j-1,n,grid);
//     int down = solve(i+1,j,n,grid);
//     int right =solve(i+1,j+1,n,grid);
//     return dp[i][j] = grid[i][j]+min({left,down,right});
// }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int res = INT_MAX;
//         vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
//         for(int i = 0;i<n;i++)
//         res = min(res,solve(0,i,n,matrix));
//         return res;
//     }
// };
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev(n);
        vector<int>curr(n);
        //fill all the base case values in dp;
        for(int i = 0;i<n;i++)
        {
            prev[i] = matrix[0][i];
        }
        for(int i = 1;i<n;i++)
        {
            
            for(int j = 0;j<n;j++)
            {
                    int left= INT_MAX,right= INT_MAX,up= INT_MAX;
                    if(j-1>=0)
                    left = matrix[i][j]+prev[j-1];
                    if(j+1<n)
                    right = matrix[i][j]+prev[j+1];
                     up = matrix[i][j]+prev[j];
                    curr[j] = min({left,right,up});   
            }
            prev = curr;
        }
        int ans = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            ans = min(ans,prev[i]);
        }
        return ans;
    }
};
