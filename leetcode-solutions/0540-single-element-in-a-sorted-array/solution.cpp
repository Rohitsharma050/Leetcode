class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (mid % 2 == 1) mid--; // Ensure mid is at an even index
            
            if (nums[mid] == nums[mid + 1]) { // Single element is in the right half
                left = mid + 2;
            } else { // Single element is in the left half
                right = mid;
            }
        }
        
        return nums[left];
    }
};

