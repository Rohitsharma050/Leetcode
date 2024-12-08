class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0); // Initialize ans with size n and default value 0
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans[i] = nums[i];
            } else if (nums[i] > 0) {
                int index = (i + nums[i]) % n; // Move forward in the circular array
                ans[i] = nums[index];
            } else {
                int index = (i - abs(nums[i]) + n) % n; // Move backward in the circular array
                if (index < 0) index += n; // Ensure index is positive
                ans[i] = nums[index];
            }
        }

        return ans;
    }
};

