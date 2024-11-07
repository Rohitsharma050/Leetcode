class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;  // Pointer for string a
        int j = b.size() - 1;  // Pointer for string b
        int carry = 0;         // Carry for addition
        string result = "";     // Result string

        // Loop until both strings are processed or there's no carry
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            // Add bit from a if available
            if (i >= 0) {
                sum += a[i] - '0';  // Convert char to int
                i--;
            }

            // Add bit from b if available
            if (j >= 0) {
                sum += b[j] - '0';  // Convert char to int
                j--;
            }

            // Calculate new bit and carry
            result = char(sum % 2 + '0') + result;  // Append the bit
            carry = sum / 2;  // Update carry
        }

        return result;
    }
};

