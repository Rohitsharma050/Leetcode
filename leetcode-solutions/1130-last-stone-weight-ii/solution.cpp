class Solution {
public:
int solve(int idx,int target,vector<int>& stones,  vector<vector<int>>&dp)
{
    if(idx<0)
    return 0;
    if(dp[idx][target]!=-1)
    return dp[idx][target];
    int nottake = solve(idx-1,target,stones,dp);
    int take = 0;
    if(stones[idx]<=target)
    {
        take = stones[idx]+solve(idx-1,target-stones[idx],stones,dp);
    }
    return dp[idx][target] =  max(take,nottake);
}
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalsum = accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(totalsum+1,-1));
        int target = totalsum/2;
        int s1 = solve(n-1,target,stones,dp);
        int s2 = totalsum-s1;
        return abs(s1-s2);
    }
};
