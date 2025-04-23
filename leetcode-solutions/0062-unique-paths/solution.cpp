// class Solution {
// public:
// vector<vector<int>>dp;
// int solve(int m,int n)
// {
//     if(m==1 && n==1)
//         return 1;
//         if(m<=0 || n<=0)
//         return 0;
//         if(dp[m][n]!=0)
//         return dp[m][n];
//         return dp[m][n] = solve(m-1,n)+solve(m,n-1);
// }
//     int uniquePaths(int m, int n) {
//         dp =vector<vector<int>>(m+1,vector<int>(n+1,0));
//      return solve(m,n);
//     }
// };
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n));
        for(int i = 0;i<n;i++)
        {
            dp[0][i] = 1;
        
        }
         for(int i = 0;i<m;i++)
        {
            
            dp[i][0] = 1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];


    }
};
