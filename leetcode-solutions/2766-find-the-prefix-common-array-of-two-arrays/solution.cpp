class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0); // Result array to store prefix common counts
        unordered_set<int> seen; // To track elements already seen
        int commonCount = 0; // Counter for common elements
        
        for (int i = 0; i < n; i++) {
            // Check if A[i] is already in the seen set
            if (seen.count(A[i])) {
                commonCount++;
            } else {
                seen.insert(A[i]); // Mark A[i] as seen
            }

            // Check if B[i] is already in the seen set
            if (seen.count(B[i])) {
                commonCount++;
            } else {
                seen.insert(B[i]); // Mark B[i] as seen
            }

            // Update the prefix common count for index i
            ans[i] = commonCount;
        }
        
        return ans;
    }
};

