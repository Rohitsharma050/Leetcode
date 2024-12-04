class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int size1 = str1.length();
        int size2 = str2.length();

        // If str2 is longer than str1, it's impossible to form a subsequence
        if (size2 > size1)
            return false;

        int i = 0; // Pointer for str1
        int j = 0; // Pointer for str2

        while (i < size1 && j < size2) {
            // Check if the characters match directly or cyclically
            if (str1[i] == str2[j] || (str1[i] == 'z' && str2[j] == 'a') || str1[i] + 1 == str2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        // If we haven't matched all characters in str2, return false
        return j == size2;
    }
};

