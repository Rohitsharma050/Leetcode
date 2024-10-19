class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length(); // Length of the input string
        map<char, int> mpp; // Map to store the frequency of characters in the current window
        int maxlen = 0; // Variable to store the maximum length of the substring found
        int maxfre = 0; // Variable to store the maximum frequency of any character in the current window
        int i = 0; // Left pointer of the sliding window

        // Iterate over the string with the right pointer 'j'
        for (int j = 0; j < len; j++) {
            mpp[s[j]]++; // Increment the frequency of the current character
            maxfre = max(maxfre, mpp[s[j]]); // Update the maximum frequency

            // Check if the current window is valid
            int count = (j - i + 1) - maxfre; // Count of characters to replace
            if (count > k) {
                // If the count exceeds k, move the left pointer to the right
                mpp[s[i]]--; // Decrease the frequency of the character at the left pointer
                i++; // Move the left pointer to the right
            }

            // Update the maximum length of the substring found
            maxlen = max(maxlen, j - i + 1);
        }
        
        return maxlen; // Return the maximum length of the substring
    }
};

