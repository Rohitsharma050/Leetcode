class Solution {
public:
int longestPalindromicSequence(int i,int j ,string &s, string &t, vector<vector<int>>&dp)
{
    if(i<0 || j<0)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(s[i]==t[j])
    {
        return dp[i][j] = 1+longestPalindromicSequence(i-1,j-1,s,t,dp);
    }
    else
    {
        return dp[i][j] = max(longestPalindromicSequence(i-1,j,s,t,dp),longestPalindromicSequence(i,j-1,s,t,dp));
    }
}
    int minInsertions(string s) {
        int n =s.length();
        string t =s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int len = longestPalindromicSequence(n-1,n-1,s,t,dp);
        return n - len;
        
    }
};
