// class Solution {
// public:
bool isPalindrome(int i,int j,string &s)
{
    
    if(i>j)
    return true;
    if(s[i]==s[j])
    {
        return isPalindrome(i+1,j-1,s);
    }
    return false;
}
// int solve(int i,int n,string &s,vector<int>&dp)
// {
//     if(i==n)
//     return 0;   
//     int ans = INT_MAX;
//     if(dp[i]!=-1)
//     return dp[i];
//     for(int j = i;j<n;j++)
//     {
//         if(isPalindrome(i,j,s))
//        {
//          int mini = 1+solve(j+1,n,s,dp);
//          ans = min(mini,ans);
//        }

//     }
//     return dp[i] = ans;
// }
//     int minCut(string s) {
//         int n = s.length();
//         vector<int>dp(n+1,-1);
//         return solve(0,n,s,dp)-1;
//     }
// };
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n+1,0);
        for(int i = n-1;i>=0;i--)
        {
            int ans = INT_MAX;
             for(int j = i;j<n;j++)
            {
                if(isPalindrome(i,j,s))
            {
                int mini = 1+dp[j+1];
                ans = min(mini,ans);
            }

            }
             dp[i] = ans;
        }
    return dp[0]-1;
    }
};
