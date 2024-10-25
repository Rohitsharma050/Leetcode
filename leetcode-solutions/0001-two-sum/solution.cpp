class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store each number and its index for quick lookup
        unordered_map<int, int> mpp;
        // Vector to store the indices of the numbers that add up to the target
        vector<int> ans;

        // Loop through the array once to check each element
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement of the current number
            int complement = target - nums[i];

            // Check if the complement is already in the map
            if (mpp.find(complement) != mpp.end()) {
                // Found a match: add the indices of the complement and current number
                ans.push_back(mpp[complement]);
                ans.push_back(i);
                break;  // Break since only one solution is required
            }

            // Store the current number and its index in the map
            mpp[nums[i]] = i;
        }

        return ans;
    }
};

