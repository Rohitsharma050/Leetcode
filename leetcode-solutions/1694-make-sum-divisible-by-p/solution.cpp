class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
        // Get the size of the input array
        int n = nums.size();
        
        // Calculate the total sum of the array mod k
        int sum = 0;
        for (int i = 0; i < n; i++) {
            // Keep adding elements and take mod k to avoid overflow
            sum = (sum + nums[i]) % k;
        }
        
        // Find the remainder (target) that needs to be removed to make sum divisible by k
        int target = sum % k;
        
        // If the total sum is already divisible by k, no need to remove any subarray
        if (target == 0)
            return 0;
        
        // Initialize the result with the size of the array (worst case)
        int result = n;
        
        // Hash map to store the prefix mod k and its index
        unordered_map<int, int> mpp;
        // Initially, map 0 to -1 to handle the case where the prefix itself is divisible by k
        mpp[0] = -1;
        
        // Variable to store the current prefix sum mod k
        int curr = 0;
        
        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Add current element to the prefix sum and take mod k
            curr = (curr + nums[i]) % k;
            
            // Find the mod that needs to be subtracted from the current prefix to make it divisible by k
            int r = (curr - target + k) % k;
            
            // Check if this mod value has been seen before
            if (mpp.find(r) != mpp.end()) {
                // If it was seen before, calculate the length of the subarray to remove
                result = min(result, i - mpp[r]);
            }
            
            // Update the current prefix sum mod k in the hash map
            mpp[curr] = i;
        }
        
        // If no valid subarray was found, return -1
        if (result == n) {
            return -1;
        }
        
        // Return the minimum length of the subarray to be removed
        return result;
    }
};

