#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        multiset<int> window; // To maintain the max and min in the current window
        int i = 0; // Start of the window
        long long ans = 0;

        for (int j = 0; j < n; ++j) {
            // Add the current element to the multiset
            window.insert(nums[j]);

            // Ensure the difference between max and min in the window is <= 2
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[i])); // Remove nums[i] from the multiset
                i++; // Shrink the window
            }

            // All subarrays ending at j and starting from i to j are valid
            ans += (j - i + 1);
        }

        return ans;
    }
};

