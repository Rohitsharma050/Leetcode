class Solution {
public:
bool canDistribute(vector<int>& nums, int maxBalls, int maxOperations) {
    int operations = 0;
    for (int balls : nums) {
        if (balls > maxBalls) {
            operations += (balls - 1) / maxBalls; // Calculate splits required
            if (operations > maxOperations) {
                return false;
            }
        }
    }
    return true;
}
    int minimumSize(vector<int>& nums, int maxOperations) {
     int left = 1, right = *max_element(nums.begin(), nums.end());
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canDistribute(nums, mid, maxOperations)) {
            result = mid;
            right = mid - 1; // Try for a smaller maxBalls value
        } else {
            left = mid + 1; // Increase maxBalls value
        }
    }

    return result;

    }
};
