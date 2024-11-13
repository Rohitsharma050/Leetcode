class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        
        // Initialize prefix and suffix arrays with 1s.
        vector<int> psum(size, 1);
        vector<int> ssum(size, 1);
        
        // Compute the prefix product for each element
        for (int i = 1; i < size; i++) {
            psum[i] = psum[i - 1] * nums[i - 1];
        }
        
        // Compute the suffix product for each element
        for (int i = size - 2; i >= 0; i--) {
            ssum[i] = ssum[i + 1] * nums[i + 1];
        }
        class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1); // Initialize result array with 1s.
        
        // Step 1: Calculate prefix products for each element.
        int prefixProduct = 1;
        for (int i = 0; i < size; i++) {
            result[i] = prefixProduct;    // Set the current result to the accumulated prefix product.
            prefixProduct *= nums[i];     // Update prefix product for the next element.
        }
        
        // Step 2: Calculate suffix products for each element and multiply with prefix product in result.
        int suffixProduct = 1;
        for (int i = size - 1; i >= 0; i--) {
            result[i] *= suffixProduct;   // Multiply the existing prefix product with the suffix product.
            suffixProduct *= nums[i];     // Update suffix product for the next element on the left.
        }
        
        return result;
    }
};

        // Calculate the final result by multiplying prefix and suffix products
        for (int i = 0; i < size; i++) {
            nums[i] = psum[i] * ssum[i];
        }
        
        return nums;
    }
};

