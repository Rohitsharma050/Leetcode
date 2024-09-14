class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  
        if (n == 1) return 1; 

        int max_value = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > max_value)
                max_value = nums[i];  
        }

        int maxans = 0;
        int current_length = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == max_value) {
                current_length++;  
            } else {
                if (current_length > maxans)
                    maxans = current_length;  
                current_length = 0;  
            }
        }

        if (current_length > maxans)
            maxans = current_length;

        return maxans;
    }
};

