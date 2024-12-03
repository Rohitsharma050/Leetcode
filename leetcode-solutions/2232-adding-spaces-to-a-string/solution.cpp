class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0; // Index for traversing the string `s`
        int j = 0; // Index for traversing the `spaces` vector
        string ans = ""; // Resultant string

        while (i < s.length()) {
            // Check if `j` is within bounds and if `i` matches the current space index
            if (j < spaces.size() && i == spaces[j]) {
                ans += ' '; // Add a space to the result
                j++; // Move to the next index in `spaces`
            } 
            ans+=s[i];
            i++;
        }

        return ans; // Return the resultant string
    }
};

