class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            // Check if the token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the top two elements for the operation
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                
                // Perform the operation based on the operator
                if (token == "+") {
                    st.push(t2 + t1);
                } else if (token == "-") {
                    st.push(t2 - t1);
                } else if (token == "*") {
                    st.push(t2 * t1);
                } else if (token == "/") {
                    st.push(t2 / t1);
                }
            } else {
                // Convert the token to an integer and push it onto the stack
                st.push(stoi(token));
            }
        }
        
        // The final result will be at the top of the stack
        return st.top();
    }
};

