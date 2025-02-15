class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            bool isGood = true;

            // Check left neighbor
            if(i - k >= 0 && nums[i] <= nums[i - k]) {
                isGood = false;
            }
            
            // Check right neighbor
            if(i + k < n && nums[i] <= nums[i + k]) {
                isGood = false;
            }
            
            // If the element is good, add it to sum
            if(isGood) {
                sum += nums[i];
            }
        }
        
        return sum;
    }
};

