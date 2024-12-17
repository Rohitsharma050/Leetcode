class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0; // Total minimum operations
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            // Step 1: Collect values at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Step 2: Calculate minimum operations (swaps)
            ans += calculateSwaps(level);
        }

        return ans;
    }

    // Function to calculate minimum swaps needed to sort a vector
    int calculateSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        unordered_map<int, int> indexMap;
        for (int i = 0; i < n; i++) {
            indexMap[arr[i]] = i; // Store original indices
        }

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            // If element is already in correct position, skip
            if (arr[i] == sortedArr[i]) continue;

            swaps++;

            // Swap the current element with the correct one
            int correctValue = sortedArr[i];
            int correctIndex = indexMap[correctValue];

            // Update index mapping after the swap
            indexMap[arr[i]] = correctIndex;
            indexMap[correctValue] = i;

            swap(arr[i], arr[correctIndex]);
        }

        return swaps;
    }
};

