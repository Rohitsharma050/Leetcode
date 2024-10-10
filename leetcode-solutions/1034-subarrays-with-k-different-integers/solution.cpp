#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int answer(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int count = 0;
        int i = 0;
        int j = 0;

        while (j < nums.size()) {
            mpp[nums[j]]++;  // Add the current element to the map
            
            // If the window has more than k distinct elements, shrink it from the left
            while (mpp.size() > k) {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0) {  // Remove the element if its count becomes zero
                    mpp.erase(nums[i]);
                }
                i++;
            }
            
            // Add the count of subarrays ending at 'j' that have at most k distinct elements
            count += (j - i + 1);

            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return answer(nums, k) - answer(nums, k - 1);
    }
};

