// class Solution {
// public:
// int solve(int i,int n,vector<int>& nums,vector<int>&dp)
// {
//     if(i>=n)
//     {
//         return 0;
//     }
//     if(dp[i]!=-1)
//     return dp[i];
//     int nottake = solve(i+1,n,nums,dp);
//     int take =nums[i]+ solve(i+2,n,nums,dp);
//     return dp[i]=max(take,nottake);
// }
//     int rob(vector<int>& nums) {     
//         int n = nums.size();
//         if(n==1)
//         return nums[0];
//         vector<int>dp(n+1,-1);
//         return max(solve(0,n-1,nums,dp),solve(1,n,nums,dp));
//     }
// };
int robhelp(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        int take = nums[i] + prev2;
        int nottake = prev1;
        int curr = max(take, nottake);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Create two subarrays: one excluding the first house, one excluding the last house
        vector<int> excludeLast(nums.begin(), nums.end() - 1); // rob from 0 to n-2
        vector<int> excludeFirst(nums.begin() + 1, nums.end()); // rob from 1 to n-1

        return max(robhelp(excludeLast), robhelp(excludeFirst));
    }
};

