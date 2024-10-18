class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Pointers for the end of both arrays and the merged position
        int i = m - 1;            // Last element in nums1's meaningful part
        int j = n - 1;            // Last element in nums2
        int k = m + n - 1;        // Last position in nums1

        // Merge the arrays starting from the end to avoid overwriting
        while (i >= 0 && j >= 0) {
            // Place the larger element at the end of nums1 and move the pointers
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If there are remaining elements in nums2, place them in nums1
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        // No need to handle remaining elements in nums1 because they are already in place
    }
};

