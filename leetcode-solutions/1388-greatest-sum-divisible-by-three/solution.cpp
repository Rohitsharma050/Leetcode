class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int mod, vector<int>& nums) {
        if (i == nums.size()) {
            return (mod == 0 ? 0 : INT_MIN);
        }

        if (dp[i][mod] != -1) return dp[i][mod];

        int take = nums[i] + solve(i + 1, (mod + nums[i]) % 3, nums);
        int skip = solve(i + 1, mod, nums);

        return dp[i][mod] = max(take, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(3, -1));

        int ans = solve(0, 0, nums);
        return ans < 0 ? 0 : ans;
    }
};

