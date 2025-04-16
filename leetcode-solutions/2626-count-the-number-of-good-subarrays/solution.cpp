class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        // freq stores the count of each number in the current sliding window
        unordered_map<int, long long> freq;
        
        long long ans = 0;   // To store the final count of valid subarrays
        long long pairs = 0; // To track number of good pairs in current window
        int left = 0;        // Left pointer of sliding window
        
        // Iterate through each index as the right end of the window
        for (int right = 0; right < nums.size(); ++right) {
            // Before adding nums[right], there are 'freq[nums[right]]' elements already present,
            // so adding this will create 'freq[nums[right]]' new good pairs
            pairs += freq[nums[right]];

            // Update the frequency of nums[right] after including it in the window
            freq[nums[right]]++;

            // Shrink the window from the left side until the number of pairs drops below k
            while (pairs >= k) {
                // All subarrays starting from index 'left' to 'right' and ending at or after 'right'
                // are valid, so we count all such subarrays
                ans += nums.size() - right;

                // Before removing nums[left], it contributes (freq[nums[left]] - 1) pairs
                freq[nums[left]]--;
                pairs -= freq[nums[left]];  // Decrease pairs accordingly

                left++;  // Move the left pointer forward to reduce window size
            }
        }

        return ans;  // Return the total count of good subarrays
    }
};

