class Solution {
public:
vector<int>dp;
int check(int i,int n,vector<int>&nums)
{
    if(i>=n)
    {

       return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int take = nums[i]+check(i+2,n,nums);
    int nottake = check(i+1,n,nums);
    return dp[i] = max(take,nottake);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n+1,-1);
        return check(0,n,nums);
    }
};
