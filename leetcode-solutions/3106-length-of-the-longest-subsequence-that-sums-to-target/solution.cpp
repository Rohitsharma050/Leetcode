class Solution {
public:
    // Declaring a 2D DP table: dp[i][target] will store the result of subproblem
    // starting from index 'i' with remaining 'target'
    vector<vector<int>> dp;

    // Recursive function to solve the problem
    int solve(int i, int n, vector<int>& nums, int target) {
        // ✅ Base Case: If target becomes 0, we've formed a valid subsequence
        // that sums up to target, return length = 0 (we'll add to it when counting)
        if (target == 0) return 0;

        // ❌ Base Case: If target becomes negative or we go out of bounds
        // it's not possible to form the required target — return INT_MIN to signal failure
        if (target < 0 || i >= n) return INT_MIN;

        // \U0001f6d1 If already computed, return from DP to avoid recomputation
        if (dp[i][target] != -1) return dp[i][target];

        // \U0001f447 Option 1: Do NOT take the current element
        int nottake = solve(i + 1, n, nums, target);

        // \U0001f447 Option 2: Take the current element if it's not more than the target
        int take = 1+solve(i+1,n,nums,target-nums[i]);

        // Memoize and return the maximum of taking or not taking
        return dp[i][target] = max(take, nottake);
    }

    // Main function to be called with input
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        // Initialize DP table with -1 meaning 'uncomputed'
        dp = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));

        // Start recursion from index 0 and full target
        int ans = solve(0, n, nums, target);

        // If no valid subsequence found, return -1
        return ans<0?-1:ans;
    }
};

