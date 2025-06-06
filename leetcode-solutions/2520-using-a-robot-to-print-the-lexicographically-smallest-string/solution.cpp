class Solution {
public:
    string robotWithString(string s) {
       int n = s.length();
    vector<char> minSuffix(n);
    
    // Step 1: Build minSuffix array
    minSuffix[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        minSuffix[i] = min(s[i], minSuffix[i + 1]);
    }
    
    stack<char> st;
    string result = "";

    // Step 2: Traverse and simulate robot operations
    for (int i = 0; i < n; ++i) {
        st.push(s[i]);
        
        // Step 3: Check if we can pop from stack
        while (!st.empty() && st.top() <= minSuffix[i + 1 == n ? n - 1 : i + 1]) {
            result += st.top();
            st.pop();
        }
    }

    // Step 4: Pop remaining characters
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;

    }
};
