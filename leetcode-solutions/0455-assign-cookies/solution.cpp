class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both arrays
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0; // Pointer for children
        int j = 0; // Pointer for cookies
        
        // Assign cookies to children
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // If the cookie satisfies the child's greed, move to the next child
                i++;
            }
            // Move to the next cookie in either case
            j++;
        }
        
        return i; // Number of satisfied children
    }
};

