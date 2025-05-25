
// class Solution {
// public:
// int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp)
// {
//     if(i<0 && j<0)
//     return 1;
//     if(i<0)
//     return 0;
//     if(j<0)
//     {
//         for(int k =0 ;k<=i;k++)
//         {
//             if(s[k]!='*')
//             return 0;
//         }
//         return 1;
//     }
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     if(s[i]==t[j] || s[i]=='?')
//     return dp[i][j]=solve(i-1,j-1,s,t,dp);
//     if(s[i]=='*')
//     {
//         bool take = solve(i,j-1,s,t,dp);
//         bool nottake = solve(i-1,j,s,t,dp);
//         return dp[i][j] = take||nottake;
//     }
    
    
//     return dp[i][j] = false;
    


// }
//     bool isMatch(string s, string p) {
//         int n = s.length();
//         int m = p.length();
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         return solve(m-1,n-1,p,s,dp);
//     }
// };
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0] = 1;
        for(int i = 1;i<=m;i++)
        {
            dp[0][i] = 0;
        }
       for (int i = 1; i <= n; i++) {
    if (p[i - 1] == '*') {
        dp[i][0] = dp[i - 1][0];
    } else {
        dp[i][0] = 0;
    }
}

        for(int i =1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(p[i-1]==s[j-1] || p[i-1]=='?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1]=='*')
                {
                    dp[i][j] = dp[i-1][j]|| dp[i][j-1];
                }
                else
                {
                    dp[i][j] =0;
                }
            }
        }
        return dp[n][m];
    }
};
