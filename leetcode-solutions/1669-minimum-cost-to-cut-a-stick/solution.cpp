// class Solution {
// public:
// int solve(int i,int j,vector<int>&cuts, vector<vector<int>>&dp)
// {
//     if(i>j)
//     return 0;
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     int ans = INT_MAX;
//     for(int k = i;k<=j;k++)
//     {
//         int mini = (cuts[j+1]-cuts[i-1])+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp) ;
//         ans = min(ans,mini);
//    }
//    return dp[i][j] =ans;
// }
//     int minCost(int n, vector<int>& cuts) {
       
//         cuts.push_back(0);
//         cuts.push_back(n);
//         sort(cuts.begin(),cuts.end());
//         int m = cuts.size();
//         vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
//         return solve(1,m-2,cuts,dp);
//     }
// };
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(m+2,vector<int>(m+2,0));
        for(int i = m;i>=1;i--)
        {
            for(int j = 1;j<=m;j++)
            {
                 if(i>j)
                continue;
                int ans = INT_MAX;
                for(int k = i;k<=j;k++)
                {
                   
                    int mini = cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    ans = min(ans,mini);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][m];
    }
};

