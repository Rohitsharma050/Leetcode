class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = n / 3;
        long long sum = 0;
        
        // Pick k medians from the end, skipping every 2 elements backwards
        for (int i = n - 2; k > 0; i -= 2, k--) {
            sum += nums[i];
        }
        
        return sum;
    }
};

