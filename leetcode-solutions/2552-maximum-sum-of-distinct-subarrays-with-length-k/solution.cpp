class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int i = 0, j = 0;
        long long sum = 0, maxSum = 0;
        map<int, int> freqMap;

        while (j < size) {
            // Add current element to the sum and frequency map
            sum += nums[j];
            freqMap[nums[j]]++;

            // Ensure window size and unique elements
            while (freqMap[nums[j]] > 1 || (j - i + 1 > k)) {
                // Shrink the window from the left
                sum -= nums[i];
                freqMap[nums[i]]--;
                if (freqMap[nums[i]] == 0) {
                    freqMap.erase(nums[i]);
                }
                i++;
            }

            // Check if the window size is exactly `k`
            if (j - i + 1 == k) {
                maxSum = max(maxSum, sum);
            }

            j++;
        }

        return maxSum;
    }
};

