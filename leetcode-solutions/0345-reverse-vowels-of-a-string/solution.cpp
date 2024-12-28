class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int j = n - 1;
        int i = 0;

        while (i <= j) {
            // Skip non-vowel characters
            while (i < j && !(s[i] == 'O' || s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'u' || 
                              s[i] == 'o' || s[i] == 'i' || s[i] == 'e' || s[i] == 'a' || s[i] == 'U')) {
                i++;
            }
            while (i < j && !(s[j] == 'O' || s[j] == 'I' || s[j] == 'E' || s[j] == 'A' || s[j] == 'u' || 
                              s[j] == 'o' || s[j] == 'i' || s[j] == 'e' || s[j] == 'a' || s[j] == 'U')) {
                j--;
            }

            // Swap vowels
            if (i <= j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};

