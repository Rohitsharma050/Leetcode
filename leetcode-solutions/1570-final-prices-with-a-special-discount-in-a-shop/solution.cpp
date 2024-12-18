class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(prices); // Copy the original prices
        stack<int> st;             // Monotonic stack to store indices

        for (int i = 0; i < n; i++) {
            // While the stack is not empty and the current price is less than or equal to the price at the top index
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                int index = st.top(); // Get the top index
                st.pop();             // Remove it from the stack
                result[index] -= prices[i]; // Apply the discount
            }
            // Push the current index onto the stack
            st.push(i);
        }

        return result;
    }
};

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         int n = prices.size();
//         for (int i = 0; i < n; i++) {   
//             for (int j = i + 1; j < n; j++) {  // Include all elements after 'i'
//                 if (prices[i] >= prices[j]) {
//                     prices[i] -= prices[j];
//                     break;  // Stop once the first valid discount is found
//                 }
//             }
//         }
//         return prices;
//     }
// };
