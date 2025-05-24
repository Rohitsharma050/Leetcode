// class Solution {
// public:
// int solve(int i,int j,string &s,string &t, vector<vector<int>>&dp)
// {
//     if(j<0)
//     return 1;
//     if(i<0)
//     return 0;
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     if(s[i]==t[j])
//     {
//         int take = solve(i-1,j-1,s,t,dp);
//         int nottake = solve(i-1,j,s,t,dp);
//         return dp[i][j] = take+nottake;
//     }
//     else
//     return dp[i][j] = solve(i-1,j,s,t,dp);
// }
//     int numDistinct(string s, string t) {
//         int n = s.length();
//         int m = t.length();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return solve(n-1,m-1,s,t,dp);
//     }
// };
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1, 0));

        // Empty string t can be formed from any prefix of s by deleting all chars
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }
};

