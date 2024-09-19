class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> index;
        index.push(-1); // Push -1 to handle edge cases where valid parentheses start from index 0
        int len = 0; // Initialize length to 0 to track the maximum valid length

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                index.push(i); // Push index of '('
            } else {
                if (!index.empty()) {
                    index.pop(); // Pop the top, as we found a matching '('
                }
                
                if (index.empty()) {
                    index.push(i); // Push current index if stack is empty after popping
                } else {
                    len = max(len, i - index.top()); // Calculate length of valid parentheses
                }
            }
        }

        return len; // Return the maximum valid length
    }
};

