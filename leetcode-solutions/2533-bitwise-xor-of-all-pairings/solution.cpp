class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        
        // Compute XOR of all elements in nums1 and nums2
        for (int num : nums1) xor1 ^= num;
        for (int num : nums2) xor2 ^= num;
        
        // Determine final result based on the sizes of nums1 and nums2
        int n = nums1.size(), m = nums2.size();
        int result = 0;
        if (n % 2 != 0) result ^= xor2; // nums2 contributes if nums1 size is odd
        if (m % 2 != 0) result ^= xor1; // nums1 contributes if nums2 size is odd
        
        return result;
    }
};

