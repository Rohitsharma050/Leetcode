class Solution {
public:
    vector<vector<int>> dp;

    bool check(int i, int n, vector<int>& nums, int sum, int target) {
        if (sum > target)
            return false;
        if (i == n)
            return sum == target;
        if (dp[i][sum] != -1)
            return dp[i][sum];

        bool take = check(i + 1, n, nums, sum + nums[i], target);
        bool nottake = check(i + 1, n, nums, sum, target);

        return dp[i][sum] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        if (totalsum % 2 != 0)
            return false;

        int target = totalsum / 2;
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(target + 1, -1));

        return check(0, n, nums, 0, target);
    }
};

