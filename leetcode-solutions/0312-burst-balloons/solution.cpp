// class Solution {
// public:
// int solve(int i,int j,vector<int>&cuts, vector<vector<int>>&dp)
// {
//     if(i>j)
//     return 0;
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     int ans = INT_MIN;
//     for(int k = i;k<=j;k++)
//     {
//         int mini = (cuts[i-1]*cuts[k]*cuts[j+1])+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp) ;
//         ans = max(ans,mini);
//    }
//    return dp[i][j] =ans;
// }
//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();
//         nums.insert(nums.begin(), 1);  
//         nums.push_back(1);            
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solve(1,n,nums,dp);
//     }
// };
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i = n;i>=1;i--){
            for(int j = 1;j<=n;j++)
            {
                if(i>j)
                continue;
                int ans = INT_MIN;
            for(int k = i;k<=j;k++)
            {
                int mini = (nums[i-1]*nums[k]*nums[j+1])+dp[i][k-1]+dp[k+1][j];
                ans = max(ans,mini);
        }
            dp[i][j] =ans;
            }
        }
        return dp[1][n];
    }
};
