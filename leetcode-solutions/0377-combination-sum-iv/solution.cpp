class Solution {
public:   
    int solve(int target,vector<int>&nums,vector<int>&dp)
    {
        
        if(target==0 )
        {
            return 1;
        }
        if(target<0)
        return 0;
        if(dp[target]!=-1)
        return dp[target];
        int take = 0;
        for(int j = 0;j<nums.size();j++)
        {
            take += solve(target-nums[j],nums,dp);
        }
        return dp[target] = take;
        
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        vector<int>dp(target+1,-1);
        ans+=solve(target,nums,dp);
        return ans;
    }
};
