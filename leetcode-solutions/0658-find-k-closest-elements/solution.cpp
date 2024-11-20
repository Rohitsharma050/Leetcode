class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;
        
        // Reduce the window size to `k` by moving pointers
        while (right - left + 1 > k) {
            if (x - arr[left] > arr[right] - x) {
                left++;
            } else {
                right--;
            }
        }
        
        // Collect the elements within the window
        vector<int> ans(arr.begin() + left, arr.begin() + right + 1);
        return ans;
    }
};

