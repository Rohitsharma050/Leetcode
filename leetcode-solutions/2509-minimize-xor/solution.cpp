class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Count the number of 1s in num2
        int count2 = __builtin_popcount(num2);
        int result = 0;
        
        // Step 1: Use bits from num1 to minimize the XOR
        for (int i = 31; i >= 0; --i) {
            if (count2 == 0) break;
            if (num1 & (1 << i)) { // If the bit is set in num1
                result |= (1 << i); // Set the same bit in result
                --count2; // Decrement the count of 1s needed
            }
        }
        
        // Step 2: Set remaining bits from the least significant bit
        for (int i = 0; i < 32; ++i) {
            if (count2 == 0) break;
            if (!(result & (1 << i))) { // If the bit is not set in result
                result |= (1 << i); // Set the bit
                --count2; // Decrement the count of 1s needed
            }
        }
        
        return result;
    }
};

