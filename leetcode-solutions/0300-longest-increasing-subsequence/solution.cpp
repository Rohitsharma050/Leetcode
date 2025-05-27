// class Solution {
// public:
// int solve(int i,int prev,vector<int>& nums,vector<vector<int>>&dp)
// {
//     if(i==nums.size())
//     return 0;
//     if(dp[i][prev+1]!=-1)
//     return dp[i][prev+1];
//     int take = 0;
//     if(prev==-1 || nums[i]>nums[prev])
//     {
//         take = 1+solve(i+1,i,nums,dp);
//     }
//     int nottake = solve(i+1,prev,nums,dp);
//     return dp[i][prev+1] = max(take,nottake);
    
// }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         return solve(0,-1,nums,dp);
//     }
// };
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//          int n = nums.size();
//         vector<int>dp(n+1,1);
//         vector<int>hash(n);
//         int maxlen = 1;
//         for(int i = 0;i<n;i++)
//         {
//             hash[i] = 1;
//             for(int j = 0;j<=i-1;j++)
//             {
//                 if(nums[j]<nums[i])
//                 {
//                     dp[i]  = max(dp[i],dp[j]+1);
//                     maxlen = max(maxlen,dp[i]);
//                 }
                
//             }
//         }
       
        
//         return maxlen;
//     }
// };
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     int n = nums.size();
        vector<int>ans;
        for(int i = 0;i<n;i++)
        {
            auto it = lower_bound(ans.begin(),ans.end(),nums[i]);
            if(it==ans.end())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                *it = nums[i];
            }
        }
        return ans.size();
    }
};
