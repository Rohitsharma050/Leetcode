class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        
        for (char c : s)
            freq[c - 'a']++;
        
        string left_half = "", center = "";
        
        // Build left half (greedy from 'a' to 'z')
        for (int i = 0; i < 26; ++i)
            left_half += string(freq[i] / 2, 'a' + i);
        
        // Find the center character if length is odd
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 == 1) {
                center += ('a' + i);
                break; // Only one odd-count char can be in center
            }
        }
        
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        
        return left_half + center + right_half;
    }
};

