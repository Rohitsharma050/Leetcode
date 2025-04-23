// class Solution {
// public:
// int solve(int i,int n,vector<int>& nums,vector<int>&dp)
// {
//     if(i>=n)
//     return 0;
//     if(dp[i]!=-1)
//     return dp[i];
//     if(i==n-1)
//     return nums[i];
    
//     int take = nums[i]+solve(i+2,n,nums,dp);
//     int nottake = solve(i+1,n,nums,dp);
//     return dp[i] = max(take,nottake);
// }
//     int rob(vector<int>& nums) {
//         int n  = nums.size();
//         vector<int>dp(n+1,-1);
//         return solve(0,n,nums,dp);
//     }
// };
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0] = nums[0];
        if(n==1)
        return dp[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i<n;i++)
        {
            int take=nums[i]+dp[i-2];
            int nottake = dp[i-1];
            dp[i] = max(take,nottake);
        }
        return max(dp[n-1],dp[n-2]);
    }
};
