/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
  int findPeakIndex(int s, int e, MountainArray &nums) {
    while (s <= e) {
        int mid = (s + e) / 2;

        // Get values with boundary checks
        int midValue = nums.get(mid);
        int leftValue = (mid > 0) ? nums.get(mid - 1) : INT_MIN;
        int rightValue = (mid < nums.length() - 1) ? nums.get(mid + 1) : INT_MIN;

        // Check if mid is the peak
        if (leftValue < midValue && rightValue < midValue) {
            return mid;
        } else if (leftValue < midValue) {
            s = mid + 1; // Peak is on the right
        } else {
            e = mid - 1; // Peak is on the left
        }
    }
    return -1; // No peak found (shouldn't happen in a valid mountain array)
}


    int findtarget1(int s, int e, int target, MountainArray &nums) {
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums.get(mid) == target) {
                return mid;
            } else if (nums.get(mid) > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1;
    }

    int findtarget2(int s, int e, int target, MountainArray &nums) {
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums.get(mid) == target) {
                return mid;
            } else if (nums.get(mid) < target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &nums) {
        int n = nums.length(); // Use length() instead of size()
        int peak = findPeakIndex(0, n - 2, nums);
        
        // Search in the ascending part
        int ans = findtarget1(0, peak, target, nums);
        if (ans != -1) return ans;

        // Search in the descending part
        return findtarget2(peak + 1, n - 1, target, nums);
    }
};

