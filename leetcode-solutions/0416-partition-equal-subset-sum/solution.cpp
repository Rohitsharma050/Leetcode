// class Solution {
// public:
// bool solve(int i,int target,vector<int>& nums,vector<vector<int>>&dp)
// {
//     if(i==0)
//     {
//         return target==nums[0];
//     }
//     if(target==0)
//     return true;
//     if(target<0)
//     return false;
//     if(dp[i][target]!=-1)
//     return dp[i][target];
//     bool nottake = solve(i-1,target,nums,dp);
//     bool take = false;
//     if(nums[i]<=target)
//     {
//         take = solve(i-1,target-nums[i],nums,dp);
//     }
//     return dp[i][target]=take||nottake;
// }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int totalsum = accumulate(nums.begin(),nums.end(),0);
//         if(totalsum%2!=0)
//         return false;
//         vector<vector<int>>dp(n+1,vector<int>((totalsum/2)+1,-1));
//         return solve(n-1,totalsum/2,nums,dp);
//     }
// };
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        if(totalsum%2!=0)
        return false;
        int target = totalsum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        for(int i = 0;i<n;i++)
        {
            dp[i][0] = true;
        }
        if(nums[0] <= target)
            dp[0][nums[0]] = true; 
        for(int i = 1;i<n;i++)
        {
            for(int j = 1;j<target+1;j++)
            {
                 bool nottake = dp[i-1][j];
                bool take = false;
                if(nums[i]<=j)
                {
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j]=take||nottake;
            }
        }
        return dp[n-1][target];
    }
};
