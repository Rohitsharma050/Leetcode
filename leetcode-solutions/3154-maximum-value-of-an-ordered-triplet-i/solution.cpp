class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; // Minimum 3 elements hone chahiye
        
        int maxPrefix = nums[0];  // nums[i] tak ka maximum
        int maxDiff = INT_MIN;    // max(nums[i] - nums[j])
        long long maxProduct = 0; // Final maximum value
        
        for (int j = 1; j < n - 1; j++) {
            maxDiff = max(maxDiff, maxPrefix - nums[j]); // Maximum (nums[i] - nums[j])
            maxPrefix = max(maxPrefix, nums[j]);         // Prefix max update karo
            maxProduct = max(maxProduct, (long long)maxDiff * nums[j + 1]); // Maximize (nums[i] - nums[j]) * nums[k]
        }
        
        return maxProduct;
    }
};

