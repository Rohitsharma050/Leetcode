class Solution {
public:
int solve(int i,int n,string &s,vector<int>&dp)
{
    if(i==n)
    return 1;
    if(s[i]=='0')
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    int first = solve(i+1,n,s,dp);
    int second = 0;
    if(i+1<n)
    {if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
    second = solve(i+2,n,s,dp);}
    return dp[i] = first+second;

   
}
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+1,-1);
        return solve(0,n,s,dp);
    }
};
