class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int ori = 0, ans = 0;

        while (j < n) {
            while ((ori & nums[j]) != 0) {  // Conflict hone par `i` badhayein
                ori ^= nums[i];  // `i` wale element ko remove karo
                i++;
            }
            ori |= nums[j];  // Current element ko include karo
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

