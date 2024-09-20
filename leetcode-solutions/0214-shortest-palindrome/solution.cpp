class Solution {
public:
vector<int> computeLPS(const string &s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0;  // length of the previous longest prefix suffix
    int i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // backtrack to the previous lps value
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
    string shortestPalindrome(string s) {
      // Create a new string by appending reverse of s with a separator
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string new_str = s + "#" + rev_s;

    // Compute the LPS array for the concatenated string
    vector<int> lps = computeLPS(new_str);

    // The last value of the LPS array tells us the longest palindromic prefix
    int longestPalindromicPrefix = lps.back();

    // The characters to be added are those after the palindromic prefix
    string to_add = s.substr(longestPalindromicPrefix);

    // Reverse the remaining part and prepend it to the original string
    reverse(to_add.begin(), to_add.end());
    return to_add + s;
}

    
};
