class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) return true;
            
            // Check if left side is sorted
            if (nums[left] < nums[mid]) {
                // Check if target is in the left sorted side
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Search left
                } else {
                    left = mid + 1; // Search right
                }
            } else if (nums[left] > nums[mid]) { // Right side is sorted
                // Check if target is in the right sorted side
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // Search right
                } else {
                    right = mid - 1; // Search left
                }
            } else { // Handle duplicates
                left++; // Skip the duplicate element
            }
        }
        
        return false; // Target not found
    }
};

