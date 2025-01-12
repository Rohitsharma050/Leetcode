class Solution {
public:
vector<int> nextGreaterElementIndices(vector<int>arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize all indices with -1
    stack<int> st;            // Stack to store indices

    for (int i = 0; i < n; ++i) {
        // While stack is not empty and the current element is greater than
        // the element at the index stored at the top of the stack
        while (!st.empty() && arr[i] > arr[st.top()]) {
            result[st.top()] = i; // Update the result with the current index
            st.pop();             // Remove the index from the stack
        }
        st.push(i); // Push the current index onto the stack
    }

    return result;
}
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge;
        vector<int>ans;
        nge = nextGreaterElementIndices(nums);
        for(int i = 0 ;i<n;i++)
        {
            if(nge[i]==-1)
            {
                ans.push_back(0);
            }
            else
            ans.push_back(abs(i-nge[i]));
        }
        return ans;
    }
};
