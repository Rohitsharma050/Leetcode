class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
      // Sort the array
        sort(nums.begin(), nums.end());

        int nextAvailable = INT_MIN; // Tracks the next distinct value
        int distinctCount = 0;

        for (int num : nums) {
            // Determine the value to assign
            int adjusted = max(nextAvailable, num - k);

            // If the adjusted value is within the allowed range
            if (adjusted <= num + k) {
                distinctCount++;
                nextAvailable = adjusted + 1; // Increment to ensure distinctness
            }
        }

        return distinctCount;
    }
};
