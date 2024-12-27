class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Perform the operation as specified
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        // Prepare the final result
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                ans.push_back(nums[i]);
            }
        }
        
        // Fill the remaining space with zeros
        while (ans.size() < n) {
            ans.push_back(0);
        }
        
        return ans;
    }
};

