class Solution {
public:

    // Helper function to check if a given substring is a palindrome
    // Takes the string `s`, and two indices `i` (start) and `j` (end) as input
    bool checkPalindrome(string s, int i, int j) {
        // Continue the loop while `i` is less than `j`
        while (i < j) {
            // If characters at positions `i` and `j` do not match, it's not a palindrome
            if (s[i++] != s[j--]) {
                return false;  // Return false if there's a mismatch
            }
        }
        return true;  // If no mismatches, return true (it is a palindrome)
    }

    // Main function to check if the string is a valid palindrome
    // We can remove at most one character to make the string a palindrome
    bool validPalindrome(string s) {
        int i = 0;                // Start from the beginning of the string
        int j = s.length() - 1;   // Start from the end of the string

        // Loop until `i` meets `j` in the middle
        while (i < j) {
            // If characters at `i` and `j` are not equal
            if (s[i] != s[j]) {
                // Try skipping one character: either skip the left character (`i + 1`) or the right character (`j - 1`)
                // If either substring is a palindrome, return true
                return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
            }
            // If characters match, move `i` to the right and `j` to the left
            i++;
            j--;
        }
        // If we complete the loop without finding mismatches, the string is already a palindrome
        return true;
    }
};

