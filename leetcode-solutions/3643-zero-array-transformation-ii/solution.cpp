class Solution {
public:
 bool canTransform(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        // Apply the first k queries using difference array
        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] += val;
            if (r + 1 < n) diff[r + 1] -= val;
        }

        // Apply the difference array and check if we can make nums[i] zero
        int current_decrement = 0;
        for (int i = 0; i < n; i++) {
            current_decrement += diff[i];
            if (nums[i] > current_decrement)
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
          int left = 0, right = queries.size(), result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canTransform(nums, queries, mid)) {
                result = mid;
                right = mid - 1;  // Try to find a smaller k
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
