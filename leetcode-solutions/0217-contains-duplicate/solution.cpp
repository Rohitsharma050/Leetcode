#include <vector>
#include <algorithm> // for sort

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // Sort the array
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) { // Compare consecutive elements
                return true; // Duplicate found
            }
        }
        return false; // No duplicates found
    }
};

