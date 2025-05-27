class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        vector<int>dp(n+1,1);
        vector<int>hash(n);
        int maxlen = 0;
        int lastindex = 0;
        for(int i = 0;i<n;i++)
        {
            hash[i] = i;
            for(int prev = 0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1)
                {
                    dp[i] = dp[prev]+1;
                    hash[i] = prev;
                }
                if(maxlen<dp[i])
                {
                    maxlen = dp[i];
                    lastindex = i;
                }
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastindex]);
        while(lastindex!=hash[lastindex])
        {
            lastindex = hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
        return ans;
    }
};
