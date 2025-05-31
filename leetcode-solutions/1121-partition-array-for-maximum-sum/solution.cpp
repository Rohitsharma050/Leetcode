// class Solution {
// public:
// int solve(int i,int n,int k,vector<int>&arr,vector<int>&dp)
// {
//     if(i==n)
//     return 0;
//     if(dp[i]!=-1)
//     return dp[i];
//     int ans = INT_MIN;
//     int len = 0;
//     int maxele = 0;
//     for(int j = i;j<min(n,i+k);j++)
//     {
//         len++;
//         maxele = max(arr[j],maxele);
//         int maxi = (len*maxele)+solve(j+1,n,k,arr,dp);
//         ans = max(ans,maxi);
//     }
//     return  dp[i] =ans;
// }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int>dp(n+1,-1);
//         return solve(0,n,k,arr,dp);
//     }
// };
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
         int n = arr.size();
        vector<int>dp(n+1,0);
        for(int i = n-1;i>=0;i--)
        {
        int ans = INT_MIN;
        int len = 0;
        int maxele = 0;
        for(int j = i;j<min(n,i+k);j++)
        {
            len++;
            maxele = max(arr[j],maxele);
            int maxi = (len*maxele)+dp[j+1];
            ans = max(ans,maxi);
        }
      dp[i] =ans;
        }
        return dp[0];
    }
};
