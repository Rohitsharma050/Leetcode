class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        bool rotated = false;

        // Count the number of times the array is rotated
        for (int i = 1; i < size; ++i) {
            if (nums[i] < nums[i - 1]) {
                if (rotated) {
                    return false; // Already rotated more than once
                }
                rotated = true;
            }
        }

        // If array is not rotated, it's already sorted
        if (!rotated) {
            return true;
        }

        // Check if rotating back to the beginning makes it sorted
        return nums[size - 1] <= nums[0];
    }
};

