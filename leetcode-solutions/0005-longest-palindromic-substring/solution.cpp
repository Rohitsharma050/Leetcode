class Solution {
public:
bool isPalindrome(int i,int j,string &s,vector<vector<int>>&dp)
{
    if(i>=j)
    return 1;
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(s[i]==s[j])
    return dp[i][j] = isPalindrome(i+1,j-1,s,dp);
    else{
        return dp[i][j] = 0;
    }
}
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlength = 0;
        int sp = -1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i = 0;i<n;i++)
        {
            for(int j =i;j<n;j++)
            {
                if(isPalindrome(i,j,s,dp))
                {
                    if(j-i+1>maxlength)
                    {
                        maxlength = j-i+1;
                        sp = i;
                    }
                }
            }
        }   
        return s.substr(sp,maxlength);
    }
};

