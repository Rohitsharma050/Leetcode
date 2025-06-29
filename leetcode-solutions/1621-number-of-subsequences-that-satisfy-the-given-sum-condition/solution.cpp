class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<int> power(n, 1);
        
        // Precompute powers of 2 up to n-1
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        sort(nums.begin(), nums.end());
        int ans = 0;
        int left = 0, right = n - 1;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + power[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};

