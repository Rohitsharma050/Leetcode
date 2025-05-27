class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
     sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int n = pairs.size();
        vector<int>dp(n+1,1);
        int maxlen = 1;
        for(int i =0 ;i<n;i++)
        {
            for(int prev = 0;prev<i;prev++)
            {
                if(pairs[i][0]>pairs[prev][1])
                {
                    dp[i] = max(dp[i],dp[prev]+1);
                  
                }
            }
              maxlen = max(maxlen,dp[i]);
        }
        return maxlen;
    }
};
