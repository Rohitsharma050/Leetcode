#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1e9+7;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        // dp[i] = # ways to partition prefix nums[0..i-1]
        // dp[0]=1 (empty prefix)
        vector<int> dp(n+1, 0), pref(n+2, 0);
        dp[0] = 1;
        pref[0] = 0;
        pref[1] = 1;  // pref[i] = dp[0] + dp[1] + ... + dp[i-1]

        deque<int> dmax, dmin;
        int left = 0;
        for(int right = 0; right < n; right++){
            // maintain deques for window [left..right]
            while(!dmax.empty() && nums[dmax.back()] <= nums[right])
                dmax.pop_back();
            dmax.push_back(right);

            while(!dmin.empty() && nums[dmin.back()] >= nums[right])
                dmin.pop_back();
            dmin.push_back(right);

            // shrink left until max-min <= k
            while(left <= right && nums[dmax.front()] - nums[dmin.front()] > k){
                if(dmax.front() == left) dmax.pop_front();
                if(dmin.front() == left) dmin.pop_front();
                left++;
            }

            // now any new segment ending at 'right' can start at j in [left..right]
            // so dp[right+1] = sum(dp[j]) for j=left..right
            int sumRange = (pref[right+1] - pref[left] + MOD) % MOD;
            dp[right+1] = sumRange;

            // update prefix sums
            pref[right+2] = (pref[right+1] + dp[right+1]) % MOD;
        }

        // total ways to partition entire array is dp[n]
        return dp[n];
    }
};

